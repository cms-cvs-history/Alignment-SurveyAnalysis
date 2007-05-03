#include "Alignment/SurveyAnalysis/test/AlignableTest.h"

AlignableTest::AlignableTest(const AlignableSurface& surface, int type):
  theType(type)
{
  setSurface(surface);
}

AlignableTest::~AlignableTest()
{
  for (unsigned int i = 0; i < theComponents.size(); ++i) delete theComponents[i];
}

void AlignableTest::addComponent(Alignable* ali)
{
  ali->setMother(this);
  theComponents.push_back(ali);
}
