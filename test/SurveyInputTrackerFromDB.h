#ifndef Alignment_SurveyAnalysis_SurveyInputTrackerFromDB_h
#define Alignment_SurveyAnalysis_SurveyInputTrackerFromDB_h

/** \class SurveyInputTrackerFromDB
 *
 *  Class to read ideal tracker from DB.
 *
 *  $Date: 2007/01/17 $
 *  $Revision: 1 $
 *  \author Chung Khim Lae
 */

#include "Alignment/SurveyAnalysis/interface/SurveyInputBase.h"

class SurveyInputTrackerFromDB:
  public SurveyInputBase
{
  public:

  SurveyInputTrackerFromDB(
			   const edm::ParameterSet&
			   ) {}

  /// Read ideal tracker geometry from DB
  virtual void beginJob(
			const edm::EventSetup&
			);

  private:

  /// Add survey info to an alignable
  void addSurveyInfo(
		     Alignable*
		     );
};

#endif
