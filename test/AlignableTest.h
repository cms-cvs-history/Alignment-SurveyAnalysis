#ifndef Alignment_SurveyAnalysis_AlignableTest_h
#define Alignment_SurveyAnalysis_AlignableTest_h

/** \class AlignableTest
 *
 *  For testing of survey analysis.
 *
 *  $Date: 2007/03/14 18:05:36 $
 *  $Revision: 1.1 $
 *  \author Chung Khim Lae
 */

#include "Alignment/CommonAlignment/interface/AlignableComposite.h"

class AlignableTest:
  public AlignableComposite
{
  public:

  AlignableTest() {}

  virtual ~AlignableTest();

  AlignableTest(const AlignableSurface&, int id);

  void addComponent(Alignable*);

  /// Return vector of direct components
  virtual std::vector<Alignable*> components() const { return theComponents; }

  /// Return the alignable type identifier
  virtual int alignableObjectId() const { return theType; }

  private:

  int theType;

  std::vector<Alignable*> theComponents;
};

#endif
