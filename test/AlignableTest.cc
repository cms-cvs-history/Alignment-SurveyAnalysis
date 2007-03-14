#include "AlignableTest.h"

AlignableTest::AlignableTest(const AlignableSurface& surface, int type):
  theType(type)
{
  setSurface(surface);
}

void AlignableTest::addComponent(Alignable* ali)
{
  ali->setMother(this);
  theComponents.push_back(ali);
}
