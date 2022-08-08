
#include "bindings.h"

BND_File3dmDithering::BND_File3dmDithering()
{
}

BND_File3dmDithering::BND_File3dmDithering(ON_Dithering* dit)
{
  SetTrackedPointer(dit);
}

//////////////////////////////////////////////////////////////////////////////

#if defined(ON_PYTHON_COMPILE)
namespace py = pybind11;
void initDitheringBindings(pybind11::module& m)
{
  py::class_<BND_File3dmDithering>(m, "Dithering")
    .def(py::init<>())
    .def(py::init<const BND_File3dmDithering&>(), py::arg("other"))
    .def_property("On", &BND_File3dmDithering::GetOn, &BND_File3dmDithering::SetOn)
    .def_property("Method", &BND_File3dmDithering::GetMethod, &BND_File3dmDithering::SetMethod)
   ;
}
#endif

#if defined(ON_WASM_COMPILE)
using namespace emscripten;

void initDitheringBindings(void*)
{
  class_<BND_File3dmDithering>("Dithering")
    .constructor<>()
    .constructor<const BND_File3dmDithering&>()
    .property("on", &BND_File3dmDithering::GetOn, &BND_File3dmDithering::SetOn)
    .property("method", &BND_File3dmDithering::GetMethod, &BND_File3dmDithering::SetMethod)
    ;
}
#endif
