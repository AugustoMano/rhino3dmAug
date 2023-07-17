#include "bindings.h"

#pragma once

#if defined(ON_PYTHON_COMPILE)
void initLinetypeBindings(pybind11::module& m);
#else
void initLinetypeBindings(void* m);
#endif

class BND_Linetype : public BND_ModelComponent
{
public:
  ON_Linetype* m_linetype = nullptr;
protected:
  void SetTrackedPointer(ON_Linetype* linetype, const ON_ModelComponentReference* compref);
public:
  BND_Linetype();
  BND_Linetype(const ON_Linetype&);
  BND_Linetype(ON_Linetype* linetype, const ON_ModelComponentReference* compref);
  virtual ~BND_Linetype();

  std::wstring GetName() const { return std::wstring(m_linetype->NameAsPointer()); }
  void SetName(const std::wstring& name) { m_linetype->SetName(name.c_str()); }
  int GetIndex() const { return m_linetype->Index(); }
  double PatternLength() const { return m_linetype->PatternLength(); }
  int SegmentCount() const { return m_linetype->SegmentCount(); }
  BND_TUPLE GetSegment(int index) const;
  bool SetSegment(int index, double length, bool isSolid);
  int AppendSegment(double length, bool isSolid);
  bool RemoveSegment(int index) { return m_linetype->RemoveSegment(index); }
  bool ClearPattern() { return m_linetype->ClearPattern(); }

#if defined(ON_PYTHON_COMPILE)
  static BND_Linetype* Border(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::Border); }
  static BND_Linetype* ByLayer(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::ByLayer); }
  static BND_Linetype* ByParent(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::ByParent); }
  static BND_Linetype* Center(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::Center); }
  static BND_Linetype* Continuous(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::Continuous); }
  static BND_Linetype* DashDot(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::DashDot); }
  static BND_Linetype* Dashed(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::Dashed); }
  static BND_Linetype* Dots(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::Dots); }
  static BND_Linetype* Hidden(pybind11::object /*self*/) { return new BND_Linetype(ON_Linetype::Hidden); }
#else
  static BND_Linetype* Border() { return new BND_Linetype(ON_Linetype::Border); }
  static BND_Linetype* ByLayer() { return new BND_Linetype(ON_Linetype::ByLayer); }
  static BND_Linetype* ByParent() { return new BND_Linetype(ON_Linetype::ByParent); }
  static BND_Linetype* Center() { return new BND_Linetype(ON_Linetype::Center); }
  static BND_Linetype* Continuous() { return new BND_Linetype(ON_Linetype::Continuous); }
  static BND_Linetype* DashDot() { return new BND_Linetype(ON_Linetype::DashDot); }
  static BND_Linetype* Dashed() { return new BND_Linetype(ON_Linetype::Dashed); }
  static BND_Linetype* Dots() { return new BND_Linetype(ON_Linetype::Dots); }
  static BND_Linetype* Hidden() { return new BND_Linetype(ON_Linetype::Hidden); }
#endif
};
