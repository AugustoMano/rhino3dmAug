
#include "bindings.h"

BND_File3dmDisplacement::BND_File3dmDisplacement(ON_3dmObjectAttributes* attr)
  :
  BND_File3dmMeshModifier(attr)
{
  if (nullptr != m_attr)
  {
    m_mm = m_ds = m_attr->MeshModifiers().Displacement();
  }
}

void BND_File3dmDisplacement::CreateNew(void)
{
  if (nullptr != m_attr)
  {
    m_mm = m_ds = m_attr->MeshModifiers().Displacement(true);
  }
}

BND_File3dmEdgeSoftening::BND_File3dmEdgeSoftening(ON_3dmObjectAttributes* attr)
  :
  BND_File3dmMeshModifier(attr)
{
  if (nullptr != m_attr)
  {
    m_mm = m_es = m_attr->MeshModifiers().EdgeSoftening();
  }
}

void BND_File3dmEdgeSoftening::CreateNew(void)
{
  if (nullptr != m_attr)
  {
    m_mm = m_es = m_attr->MeshModifiers().EdgeSoftening(true);
  }
}

BND_File3dmThickening::BND_File3dmThickening(ON_3dmObjectAttributes* attr)
  :
  BND_File3dmMeshModifier(attr)
{
  if (nullptr != m_attr)
  {
    m_mm = m_th = m_attr->MeshModifiers().Thickening();
  }
}

void BND_File3dmThickening::CreateNew(void)
{
  if (nullptr != m_attr)
  {
    m_mm = m_th = m_attr->MeshModifiers().Thickening(true);
  }
}

BND_File3dmCurvePiping::BND_File3dmCurvePiping(ON_3dmObjectAttributes* attr)
  :
  BND_File3dmMeshModifier(attr)
{
  if (nullptr != m_attr)
  {
    m_mm = m_cp = m_attr->MeshModifiers().CurvePiping();
  }
}

void BND_File3dmCurvePiping::CreateNew(void)
{
  if (nullptr != m_attr)
  {
    m_mm = m_cp = m_attr->MeshModifiers().CurvePiping(true);
  }
}

BND_File3dmShutlining::BND_File3dmShutlining(ON_3dmObjectAttributes* attr)
  :
  BND_File3dmMeshModifier(attr)
{
  if (nullptr != m_attr)
  {
    m_mm = m_sl = m_attr->MeshModifiers().Shutlining();
  }
}

void BND_File3dmShutlining::CreateNew(void)
{
  if (nullptr != m_attr)
  {
    m_mm = m_sl = m_attr->MeshModifiers().Shutlining(true);
  }
}

int BND_File3dmShutliningCurveTable::Count() const
{
  int count = 0;

  auto it = m_sl->GetCurveIterator();
  while (nullptr != it.Next())
  {
    count++;
  }

  return count;
}

void BND_File3dmShutliningCurveTable::Add(BND_UUID id)
{
  if (nullptr != m_sl)
  {
    auto& curve = m_sl->AddCurve();
    curve.SetId(Binding_to_ON_UUID(id));
  }
}

BND_File3dmShutliningCurve* BND_File3dmShutliningCurveTable::FindIndex(int index)
{
  if (nullptr == m_sl)
    return nullptr;

  int count = 0;

  auto it = m_sl->GetCurveIterator();
  while (auto* c = it.Next())
  {
    if (count == index)
    {
      return new BND_File3dmShutliningCurve(c);
    }

    count++;
  }

  return nullptr;
}

BND_File3dmShutliningCurve* BND_File3dmShutliningCurveTable::IterIndex(int index)
{
  return FindIndex(index);
}

BND_File3dmShutliningCurve* BND_File3dmShutliningCurveTable::FindId(BND_UUID id)
{
  if (nullptr == m_sl)
    return nullptr;

  auto it = m_sl->GetCurveIterator();
  while (auto* c = it.Next())
  {
    if (c->Id() == Binding_to_ON_UUID(id))
    {
      return new BND_File3dmShutliningCurve(c); // I don't understand the ownership around this object.
    }
  }

  return nullptr;
}

//////////////////////////////////////////////////////////////////////////////

#if defined(ON_PYTHON_COMPILE)
namespace py = pybind11;
void initMeshModifierBindings(pybind11::module& m)
{
  py::class_<BND_File3dmDisplacement>(m, "Displacement")
    .def(py::init<>())
    .def(py::init<const BND_File3dmDisplacement&>(), py::arg("other"))
    .def_property("On", &BND_File3dmDisplacement::On, &BND_File3dmDisplacement::SetOn)
    .def_property("Texture", &BND_File3dmDisplacement::Texture, &BND_File3dmDisplacement::SetTexture)
    .def_property("BlackPoint", &BND_File3dmDisplacement::BlackPoint, &BND_File3dmDisplacement::SetBlackPoint)
    .def_property("WhitePoint", &BND_File3dmDisplacement::WhitePoint, &BND_File3dmDisplacement::SetWhitePoint)
    .def_property("PostWeldAngle", &BND_File3dmDisplacement::PostWeldAngle, &BND_File3dmDisplacement::SetPostWeldAngle)
    .def_property("FairingOn", &BND_File3dmDisplacement::FairingOn, &BND_File3dmDisplacement::SetFairingOn)
    .def_property("Fairing", &BND_File3dmDisplacement::Fairing, &BND_File3dmDisplacement::SetFairing)
    .def_property("FinalMaxFaces", &BND_File3dmDisplacement::FinalMaxFaces, &BND_File3dmDisplacement::SetFinalMaxFaces)
    .def_property("FinalMaxFacesOn", &BND_File3dmDisplacement::FinalMaxFacesOn, &BND_File3dmDisplacement::SetFinalMaxFacesOn)
    .def_property("InitialQuality", &BND_File3dmDisplacement::InitialQuality, &BND_File3dmDisplacement::SetInitialQuality)
    .def_property("MappingChannel", &BND_File3dmDisplacement::MappingChannel, &BND_File3dmDisplacement::SetMappingChannel)
    .def_property("MeshMemoryLimit", &BND_File3dmDisplacement::MeshMemoryLimit, &BND_File3dmDisplacement::SetMeshMemoryLimit)
    .def_property("RefineSteps", &BND_File3dmDisplacement::RefineSteps, &BND_File3dmDisplacement::SetRefineSteps)
    .def_property("RefineSensitivity", &BND_File3dmDisplacement::RefineSensitivity, &BND_File3dmDisplacement::SetRefineSensitivity)
    .def_property("SweepResolutionFormula", &BND_File3dmDisplacement::SweepResolutionFormula, &BND_File3dmDisplacement::SetSweepResolutionFormula)
    ;

  py::class_<BND_File3dmEdgeSoftening>(m, "EdgeSoftening")
    .def(py::init<>())
    .def(py::init<const BND_File3dmEdgeSoftening&>(), py::arg("other"))
    .def_property("On", &BND_File3dmEdgeSoftening::On, &BND_File3dmEdgeSoftening::SetOn)
    .def_property("Softening", &BND_File3dmEdgeSoftening::Softening, &BND_File3dmEdgeSoftening::SetSoftening)
    .def_property("Chamfer", &BND_File3dmEdgeSoftening::Chamfer, &BND_File3dmEdgeSoftening::SetChamfer)
    .def_property("Faceted", &BND_File3dmEdgeSoftening::Faceted, &BND_File3dmEdgeSoftening::SetFaceted)
    .def_property("EdgeAngleThreshold", &BND_File3dmEdgeSoftening::EdgeAngleThreshold, &BND_File3dmEdgeSoftening::SetEdgeAngleThreshold)
    .def_property("ForceSoftening", &BND_File3dmEdgeSoftening::ForceSoftening, &BND_File3dmEdgeSoftening::SetForceSoftening)
    ;

  py::class_<BND_File3dmThickening>(m, "Thickening")
    .def(py::init<>())
    .def(py::init<const BND_File3dmThickening&>(), py::arg("other"))
    .def_property("On", &BND_File3dmThickening::On, &BND_File3dmThickening::SetOn)
    .def_property("Distance", &BND_File3dmThickening::Distance, &BND_File3dmThickening::SetDistance)
    .def_property("Solid", &BND_File3dmThickening::Solid, &BND_File3dmThickening::SetSolid)
    .def_property("OffsetOnly", &BND_File3dmThickening::OffsetOnly, &BND_File3dmThickening::SetOffsetOnly)
    .def_property("BothSides", &BND_File3dmThickening::BothSides, &BND_File3dmThickening::SetBothSides)
    ;

  py::class_<BND_File3dmCurvePiping>(m, "CurvePiping")
    .def(py::init<>())
    .def(py::init<const BND_File3dmCurvePiping&>(), py::arg("other"))
    .def_property("On", &BND_File3dmCurvePiping::On, &BND_File3dmCurvePiping::SetOn)
    .def_property("Radius", &BND_File3dmCurvePiping::Radius, &BND_File3dmCurvePiping::SetRadius)
    .def_property("Segments", &BND_File3dmCurvePiping::Segments, &BND_File3dmCurvePiping::SetSegments)
    .def_property("Faceted", &BND_File3dmCurvePiping::Faceted, &BND_File3dmCurvePiping::SetFaceted)
    .def_property("Accuracy", &BND_File3dmCurvePiping::Accuracy, &BND_File3dmCurvePiping::SetAccuracy)
    .def_property("CapType", &BND_File3dmCurvePiping::CapType, &BND_File3dmCurvePiping::SetCapType)
    ;

  py::class_<BND_File3dmShutliningCurve>(m, "ShutliningCurve")
    .def(py::init<>())
    .def(py::init<const BND_File3dmShutliningCurve&>(), py::arg("other"))
    .def_property("Id", &BND_File3dmShutliningCurve::Id, &BND_File3dmShutliningCurve::SetId)
    .def_property("Radius", &BND_File3dmShutliningCurve::Radius, &BND_File3dmShutliningCurve::SetRadius)
    .def_property("Profile", &BND_File3dmShutliningCurve::Profile, &BND_File3dmShutliningCurve::SetProfile)
    .def_property("Enabled", &BND_File3dmShutliningCurve::Enabled, &BND_File3dmShutliningCurve::SetEnabled)
    .def_property("Pull", &BND_File3dmShutliningCurve::Pull, &BND_File3dmShutliningCurve::SetPull)
    .def_property("IsBump", &BND_File3dmShutliningCurve::IsBump, &BND_File3dmShutliningCurve::SetIsBump)
    ;

  py::class_<BND_File3dmShutlining>(m, "Shutlining")
    .def(py::init<>())
    .def(py::init<const BND_File3dmShutlining&>(), py::arg("other"))
    .def_property("On", &BND_File3dmShutlining::On, &BND_File3dmShutlining::SetOn)
    .def_property("Faceted", &BND_File3dmShutlining::Faceted, &BND_File3dmShutlining::SetFaceted)
    .def_property("AutoUpdate", &BND_File3dmShutlining::AutoUpdate, &BND_File3dmShutlining::SetAutoUpdate)
    .def_property("ForceUpdate", &BND_File3dmShutlining::ForceUpdate, &BND_File3dmShutlining::SetForceUpdate)
    .def_property("ForceUpdate", &BND_File3dmShutlining::ForceUpdate, &BND_File3dmShutlining::SetForceUpdate)
    .def_property_readonly("Curves", &BND_File3dmShutlining::Curves)
    .def("DeleteAllCurves", &BND_File3dmShutlining::DeleteAllCurves)
    ;
}
#endif

#if defined(ON_WASM_COMPILE)
using namespace emscripten;

void initMeshModifierBindings(void*)
{
  class_<BND_File3dmDisplacement>("Displacement")
    .constructor<>()
    .constructor<const BND_File3dmDisplacement&>()
    .property("on", &BND_File3dmDisplacement::On, &BND_File3dmDisplacement::SetOn)
    .property("texture", &BND_File3dmDisplacement::Texture, &BND_File3dmDisplacement::SetTexture)
    .property("blackPoint", &BND_File3dmDisplacement::BlackPoint, &BND_File3dmDisplacement::SetBlackPoint)
    .property("whitePoint", &BND_File3dmDisplacement::WhitePoint, &BND_File3dmDisplacement::SetWhitePoint)
    .property("postWeldAngle", &BND_File3dmDisplacement::PostWeldAngle, &BND_File3dmDisplacement::SetPostWeldAngle)
    .property("fairingOn", &BND_File3dmDisplacement::FairingOn, &BND_File3dmDisplacement::SetFairingOn)
    .property("fairing", &BND_File3dmDisplacement::Fairing, &BND_File3dmDisplacement::SetFairing)
    .property("finalMaxFaces", &BND_File3dmDisplacement::FinalMaxFaces, &BND_File3dmDisplacement::SetFinalMaxFaces)
    .property("finalMaxFacesOn", &BND_File3dmDisplacement::FinalMaxFacesOn, &BND_File3dmDisplacement::SetFinalMaxFacesOn)
    .property("initialQuality", &BND_File3dmDisplacement::InitialQuality, &BND_File3dmDisplacement::SetInitialQuality)
    .property("mappingChannel", &BND_File3dmDisplacement::MappingChannel, &BND_File3dmDisplacement::SetMappingChannel)
    .property("meshMemoryLimit", &BND_File3dmDisplacement::MeshMemoryLimit, &BND_File3dmDisplacement::SetMeshMemoryLimit)
    .property("refineSteps", &BND_File3dmDisplacement::RefineSteps, &BND_File3dmDisplacement::SetRefineSteps)
    .property("refineSensitivity", &BND_File3dmDisplacement::RefineSensitivity, &BND_File3dmDisplacement::SetRefineSensitivity)
    .property("sweepResolutionFormula", &BND_File3dmDisplacement::SweepResolutionFormula, &BND_File3dmDisplacement::SweepResolutionFormula)
    ;

  class_<BND_File3dmEdgeSoftening>("EdgeSoftening")
    .constructor<>()
    .constructor<const BND_File3dmEdgeSoftening&>()
    .property("on", &BND_File3dmEdgeSoftening::On, &BND_File3dmEdgeSoftening::SetOn)
    .property("softening", &BND_File3dmEdgeSoftening::Softening, &BND_File3dmEdgeSoftening::SetSoftening)
    .property("chamfer", &BND_File3dmEdgeSoftening::Chamfer, &BND_File3dmEdgeSoftening::SetChamfer)
    .property("faceted", &BND_File3dmEdgeSoftening::Faceted, &BND_File3dmEdgeSoftening::SetFaceted)
    .property("edgeAngleThreshold", &BND_File3dmEdgeSoftening::EdgeAngleThreshold, &BND_File3dmEdgeSoftening::SetEdgeAngleThreshold)
    .property("forceSoftening", &BND_File3dmEdgeSoftening::ForceSoftening, &BND_File3dmEdgeSoftening::SetForceSoftening)
    ;

  class_<BND_File3dmThickening>("Thickening")
    .constructor<>()
    .constructor<const BND_File3dmThickening&>()
    .property("on", &BND_File3dmThickening::On, &BND_File3dmThickening::SetOn)
    .property("distance", &BND_File3dmThickening::Distance, &BND_File3dmThickening::SetDistance)
    .property("solid", &BND_File3dmThickening::Solid, &BND_File3dmThickening::SetSolid)
    .property("offsetOnly", &BND_File3dmThickening::OffsetOnly, &BND_File3dmThickening::SetOffsetOnly)
    .property("bothSides", &BND_File3dmThickening::BothSides, &BND_File3dmThickening::SetBothSides)
    ;

  class_<BND_File3dmCurvePiping>("CurvePiping")
    .constructor<>()
    .constructor<const BND_File3dmCurvePiping&>()
    .property("on", &BND_File3dmCurvePiping::On, &BND_File3dmCurvePiping::SetOn)
    .property("radius", &BND_File3dmCurvePiping::Radius, &BND_File3dmCurvePiping::SetRadius)
    .property("segments", &BND_File3dmCurvePiping::Segments, &BND_File3dmCurvePiping::SetSegments)
    .property("faceted", &BND_File3dmCurvePiping::Faceted, &BND_File3dmCurvePiping::SetFaceted)
    .property("accuracy", &BND_File3dmCurvePiping::Accuracy, &BND_File3dmCurvePiping::SetAccuracy)
    .property("capType", &BND_File3dmCurvePiping::CapType, &BND_File3dmCurvePiping::SetCapType)
    ;

  class_<BND_File3dmShutliningCurve>(m, "ShutliningCurve")
    .constructor<>()
    .constructor<const BND_File3dmShutliningCurve&>()
    .property("Id", &BND_File3dmShutliningCurve::Id, &BND_File3dmShutliningCurve::SetId)
    .property("Radius", &BND_File3dmShutliningCurve::Radius, &BND_File3dmShutliningCurve::SetRadius)
    .property("Profile", &BND_File3dmShutliningCurve::Profile, &BND_File3dmShutliningCurve::SetProfile)
    .property("Enabled", &BND_File3dmShutliningCurve::Enabled, &BND_File3dmShutliningCurve::SetEnabled)
    .property("Pull", &BND_File3dmShutliningCurve::Pull, &BND_File3dmShutliningCurve::SetPull)
    .property("IsBump", &BND_File3dmShutliningCurve::IsBump, &BND_File3dmShutliningCurve::SetIsBump)
    ;

  class_<BND_File3dmShutlining>("Shutlining")
    .constructor<>()
    .constructor<const BND_File3dmShutlining&>()
    .property("On", &BND_File3dmShutlining::On, &BND_File3dmShutlining::SetOn)
    .property("Faceted", &BND_File3dmShutlining::Faceted, &BND_File3dmShutlining::SetFaceted)
    .property("AutoUpdate", &BND_File3dmShutlining::AutoUpdate, &BND_File3dmShutlining::SetAutoUpdate)
    .property("ForceUpdate", &BND_File3dmShutlining::ForceUpdate, &BND_File3dmShutlining::SetForceUpdate)
    .property("Curves", &BND_File3dmShutlining::Curves)
    .function("DeleteAllCurves", &BND_File3dmShutlining::DeleteAllCurves)
    ;
}
#endif
 