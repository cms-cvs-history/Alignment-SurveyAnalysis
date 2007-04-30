#include "Alignment/CommonAlignment/interface/SurveyDet.h"
#include "Alignment/TrackerAlignment/interface/AlignableTracker.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeomBuilderFromGeometricDet.h"

#include "Alignment/SurveyAnalysis/test/SurveyInputTrackerFromDB.h"

void SurveyInputTrackerFromDB::beginJob(const edm::EventSetup& setup)
{
  edm::ESHandle<DDCompactView> view;
  edm::ESHandle<GeometricDet>  geom;

  setup.get<IdealGeometryRecord>().get(view);
  setup.get<IdealGeometryRecord>().get(geom);

  TrackerGeometry* tracker =
    TrackerGeomBuilderFromGeometricDet().build(&*view, &*geom);
	
  addComponent( new AlignableTracker(&*geom, tracker) );
  addSurveyInfo( detector() );
}

void SurveyInputTrackerFromDB::addSurveyInfo(Alignable* ali)
{
  const std::vector<Alignable*>& comp = ali->components();

  unsigned int nComp = comp.size();

  for (unsigned int i = 0; i < nComp; ++i) addSurveyInfo(comp[i]);

  align::ErrorMatrix error = ROOT::Math::SMatrixIdentity();

  ali->setSurvey( new SurveyDet(ali->surface(), error *= 1e-6) );
}
