
#pragma once

#include "bindings.h"

#if defined(ON_PYTHON_COMPILE)
void initMeshModifierBindings(pybind11::module& m);
#else
void initMeshModifierBindings(void* m);
#endif

class BND_File3dmMeshModifier
{
protected:
  ON_MeshModifier* m_mm = nullptr;
  ON_3dmObjectAttributes* m_attr = nullptr;

  BND_File3dmMeshModifier(ON_3dmObjectAttributes* attr) : m_attr(attr) { }

public:
  bool Exists(void) const { return (nullptr != m_mm); }
  void EnsureExists(void) { if (nullptr == m_mm) CreateNew(); }

protected:
  virtual void CreateNew(void) = 0;
};

class BND_File3dmDisplacement : public BND_File3dmMeshModifier
{
private:
  ON_Displacement* m_ds = nullptr;

public:
  BND_File3dmDisplacement(ON_3dmObjectAttributes* attr=nullptr);

  using SRF = ON_Displacement::SweepResolutionFormulas;
  bool     On(void)                 const { return (nullptr != m_ds) ? m_ds->On()                : false; }
  double   BlackPoint(void)         const { return (nullptr != m_ds) ? m_ds->BlackPoint()        : 0.0; }
  double   WhitePoint(void)         const { return (nullptr != m_ds) ? m_ds->WhitePoint()        : 0.0; }
  double   PostWeldAngle(void)      const { return (nullptr != m_ds) ? m_ds->PostWeldAngle()     : 0.0; }
  bool     FairingOn(void)          const { return (nullptr != m_ds) ? m_ds->FairingOn()         : false; }
  int      Fairing(void)            const { return (nullptr != m_ds) ? m_ds->Fairing()           : 0; }
  int      FinalMaxFaces(void)      const { return (nullptr != m_ds) ? m_ds->FinalMaxFaces()     : 0; }
  bool     FinalMaxFacesOn(void)    const { return (nullptr != m_ds) ? m_ds->FinalMaxFacesOn()   : false; }
  int      InitialQuality(void)     const { return (nullptr != m_ds) ? m_ds->InitialQuality()    : 0; }
  int      MappingChannel(void)     const { return (nullptr != m_ds) ? m_ds->MappingChannel()    : 0; }
  int      MeshMemoryLimit(void)    const { return (nullptr != m_ds) ? m_ds->MeshMemoryLimit()   : 0; }
  int      RefineSteps(void)        const { return (nullptr != m_ds) ? m_ds->RefineSteps()       : 0; }
  double   RefineSensitivity(void)  const { return (nullptr != m_ds) ? m_ds->RefineSensitivity() : 0.0; }
  SRF  SweepResolutionFormula(void) const { return (nullptr != m_ds) ? m_ds->SweepResolutionFormula() : SRF::Default; }
  BND_UUID Texture(void)            const { return ON_UUID_to_Binding((nullptr != m_ds) ? m_ds->Texture() : ON_nil_uuid); }

  void SetOn(bool v)                    const { if (nullptr != m_ds) m_ds->SetOn(v); }
  void SetBlackPoint(double v)          const { if (nullptr != m_ds) m_ds->SetBlackPoint(v); }
  void SetWhitePoint(double v)          const { if (nullptr != m_ds) m_ds->SetWhitePoint(v); }
  void SetFairing(int v)                const { if (nullptr != m_ds) m_ds->SetFairing(v); }
  void SetFairingOn(bool v)             const { if (nullptr != m_ds) m_ds->SetFairingOn(v); }
  void SetFinalMaxFaces(int v)          const { if (nullptr != m_ds) m_ds->SetFinalMaxFaces(v); }
  void SetFinalMaxFacesOn(bool v)       const { if (nullptr != m_ds) m_ds->SetFinalMaxFacesOn(v); }
  void SetInitialQuality(int v)         const { if (nullptr != m_ds) m_ds->SetInitialQuality(v); }
  void SetMappingChannel(int v)         const { if (nullptr != m_ds) m_ds->SetMappingChannel(v); }
  void SetMeshMemoryLimit(int v)        const { if (nullptr != m_ds) m_ds->SetMeshMemoryLimit(v); }
  void SetPostWeldAngle(double v)       const { if (nullptr != m_ds) m_ds->SetPostWeldAngle(v); }
  void SetRefineSteps(int v)            const { if (nullptr != m_ds) m_ds->SetRefineSteps(v); }
  void SetRefineSensitivity(double v)   const { if (nullptr != m_ds) m_ds->SetRefineSensitivity(v); }
  void SetSweepResolutionFormula(SRF v) const { if (nullptr != m_ds) m_ds->SetSweepResolutionFormula(v); }
  void SetTexture(const BND_UUID& v)    const { if (nullptr != m_ds) m_ds->SetTexture(Binding_to_ON_UUID(v)); }

protected:
  virtual void CreateNew(void) override;
};

class BND_File3dmEdgeSoftening : public BND_File3dmMeshModifier
{
private:
  ON_EdgeSoftening* m_es = nullptr;

public:
  BND_File3dmEdgeSoftening(ON_3dmObjectAttributes* attr=nullptr);

  bool    On(void)                 const { return (nullptr != m_es) ? m_es->On()                 : false; }
  double  Softening(void)          const { return (nullptr != m_es) ? m_es->Softening()          : 0.0; }
  bool    Chamfer(void)            const { return (nullptr != m_es) ? m_es->Chamfer()            : false; }
  bool    Faceted(void)            const { return (nullptr != m_es) ? m_es->Faceted()            : false; }
  double  EdgeAngleThreshold(void) const { return (nullptr != m_es) ? m_es->EdgeAngleThreshold() : 0.0; }
  bool    ForceSoftening(void)     const { return (nullptr != m_es) ? m_es->ForceSoftening()     : false; }

  void SetOn(bool v)                   const { if (nullptr != m_es) m_es->SetOn(v); }
  void SetSoftening(double v)          const { if (nullptr != m_es) m_es->SetSoftening(v); }
  void SetChamfer(bool v)              const { if (nullptr != m_es) m_es->SetChamfer(v); }
  void SetFaceted(bool v)              const { if (nullptr != m_es) m_es->SetFaceted(v); }
  void SetEdgeAngleThreshold(double v) const { if (nullptr != m_es) m_es->SetEdgeAngleThreshold(v); }
  void SetForceSoftening(bool v)       const { if (nullptr != m_es) m_es->SetForceSoftening(v); }

protected:
  virtual void CreateNew(void) override;
};

class BND_File3dmThickening : public BND_File3dmMeshModifier
{
private:
  ON_Thickening* m_th = nullptr;

public:
  BND_File3dmThickening(ON_3dmObjectAttributes* attr=nullptr);

  bool   On(void)         const { return (nullptr != m_th) ? m_th->On()         : false; }
  double Distance(void)   const { return (nullptr != m_th) ? m_th->Distance()   : 0.0;   }
  bool   Solid(void)      const { return (nullptr != m_th) ? m_th->Solid()      : false; }
  bool   OffsetOnly(void) const { return (nullptr != m_th) ? m_th->OffsetOnly() : false; }
  bool   BothSides(void)  const { return (nullptr != m_th) ? m_th->BothSides()  : false; }

  void SetOn(bool v)         const { if (nullptr != m_th) m_th->SetOn(v); }
  void SetDistance(double v) const { if (nullptr != m_th) m_th->SetDistance(v); }
  void SetSolid(bool v)      const { if (nullptr != m_th) m_th->SetSolid(v); }
  void SetOffsetOnly(bool v) const { if (nullptr != m_th) m_th->SetOffsetOnly(v); }
  void SetBothSides(bool v)  const { if (nullptr != m_th) m_th->SetBothSides(v) ; }

protected:
  virtual void CreateNew(void) override;
};

class BND_File3dmCurvePiping : public BND_File3dmMeshModifier
{
private:
  ON_CurvePiping* m_cp = nullptr;

public:
  BND_File3dmCurvePiping(ON_3dmObjectAttributes* attr=nullptr);

  using CT = ON_CurvePiping::CapTypes;

  bool   On(void)       const { return (nullptr != m_cp) ? m_cp->On()       : false; }
  double Radius(void)   const { return (nullptr != m_cp) ? m_cp->Radius()   : 0.0; }
  int    Segments(void) const { return (nullptr != m_cp) ? m_cp->Segments() : 0; }
  bool   Faceted(void)  const { return (nullptr != m_cp) ? m_cp->Faceted()  : false; }
  int    Accuracy(void) const { return (nullptr != m_cp) ? m_cp->Accuracy() : 0; }
  CT     CapType(void)  const { return (nullptr != m_cp) ? m_cp->CapType()  : CT::None; }

  void SetOn(bool v)       const { if (nullptr != m_cp) m_cp->SetOn(v); }
  void SetRadius(double v) const { if (nullptr != m_cp) m_cp->SetRadius(v); }
  void SetSegments(int v)  const { if (nullptr != m_cp) m_cp->SetSegments(v); }
  void SetFaceted(bool v)  const { if (nullptr != m_cp) m_cp->SetFaceted(v); }
  void SetAccuracy(int v)  const { if (nullptr != m_cp) m_cp->SetAccuracy(v); }
  void SetCapType(CT v)    const { if (nullptr != m_cp) m_cp->SetCapType(v); }

protected:
  virtual void CreateNew(void) override;
};

class BND_File3dmShutLiningCurve
{
private:
  ON_ShutLining::Curve* m_c = nullptr;

public:
  BND_File3dmShutLiningCurve(ON_ShutLining::Curve* c=nullptr) : m_c(c) { }

  double Radius(void)  const { return (nullptr != m_c) ? m_c->Radius()  : 0.0;   }
  int    Profile(void) const { return (nullptr != m_c) ? m_c->Profile() : 0;     }
  bool   Enabled(void) const { return (nullptr != m_c) ? m_c->Enabled() : false; }
  bool   Pull(void)    const { return (nullptr != m_c) ? m_c->Pull()    : false; }
  bool   IsBump(void)  const { return (nullptr != m_c) ? m_c->IsBump()  : false; }
  BND_UUID Id(void)    const { return ON_UUID_to_Binding((nullptr != m_c) ? m_c->Id() : ON_nil_uuid); }

  void SetRadius(double v)      const { if (nullptr != m_c) m_c->SetRadius(v); }
  void SetProfile(int v)        const { if (nullptr != m_c) m_c->SetProfile(v); }
  void SetEnabled(bool v)       const { if (nullptr != m_c) m_c->SetEnabled(v); }
  void SetPull(bool v)          const { if (nullptr != m_c) m_c->SetPull(v); }
  void SetIsBump(bool v)        const { if (nullptr != m_c) m_c->SetIsBump(v); }
  void SetId(const BND_UUID& v) const { if (nullptr != m_c) m_c->SetId(Binding_to_ON_UUID(v)); }
};

class BND_File3dmShutLiningCurveTable
{
private:
  ON_ShutLining* m_sl = nullptr;

public:
  BND_File3dmShutLiningCurveTable(ON_ShutLining* sl=nullptr) : m_sl(sl) { }

  int Count() const;
  void Add(BND_UUID id);
  BND_File3dmShutLiningCurve* FindIndex(int index);
  BND_File3dmShutLiningCurve* IterIndex(int index); // helper function for iterator
  BND_File3dmShutLiningCurve* FindId(BND_UUID id);
};

class BND_File3dmShutLining : public BND_File3dmMeshModifier
{
private:
  ON_ShutLining* m_sl = nullptr;

public:
  BND_File3dmShutLining(ON_3dmObjectAttributes* attr=nullptr);

  bool On(void)          const { return (nullptr != m_sl) ? m_sl->On()          : false; }
  bool Faceted(void)     const { return (nullptr != m_sl) ? m_sl->Faceted()     : false; }
  bool AutoUpdate(void)  const { return (nullptr != m_sl) ? m_sl->AutoUpdate()  : false; }
  bool ForceUpdate(void) const { return (nullptr != m_sl) ? m_sl->ForceUpdate() : false; }

  void SetOn(bool v)          const { if (nullptr != m_sl) m_sl->SetOn(v); }
  void SetFaceted(bool v)     const { if (nullptr != m_sl) m_sl->SetFaceted(v); }
  void SetAutoUpdate(bool v)  const { if (nullptr != m_sl) m_sl->SetAutoUpdate(v); }
  void SetForceUpdate(bool v) const { if (nullptr != m_sl) m_sl->SetForceUpdate(v); }

  BND_File3dmShutLiningCurveTable Curves() { return BND_File3dmShutLiningCurveTable(m_sl); }

  void DeleteAllCurves(void) const { if (nullptr != m_sl) m_sl->DeleteAllCurves(); }

protected:
  virtual void CreateNew(void) override;
};

class BND_File3dmMeshModifiers
{
private:
  BND_File3dmDisplacement  m_displacement;
  BND_File3dmEdgeSoftening m_edge_softening;
  BND_File3dmThickening    m_thickening;
  BND_File3dmCurvePiping   m_curve_piping;
  BND_File3dmShutLining    m_shutlining;

public:
  BND_File3dmMeshModifiers() { }
  BND_File3dmMeshModifiers(ON_3dmObjectAttributes* attr);

  BND_File3dmDisplacement*  Displacement()  { return m_displacement  .Exists() ? &m_displacement   : nullptr; }
  BND_File3dmEdgeSoftening* EdgeSoftening() { return m_edge_softening.Exists() ? &m_edge_softening : nullptr; }
  BND_File3dmThickening*    Thickening()    { return m_thickening    .Exists() ? &m_thickening     : nullptr; }
  BND_File3dmCurvePiping*   CurvePiping()   { return m_curve_piping  .Exists() ? &m_curve_piping   : nullptr; }
  BND_File3dmShutLining*    ShutLining()    { return m_shutlining    .Exists() ? &m_shutlining     : nullptr; }

  BND_File3dmDisplacement&  CreateDisplacement()  { m_displacement  .EnsureExists(); return m_displacement; }
  BND_File3dmEdgeSoftening& CreateEdgeSoftening() { m_edge_softening.EnsureExists(); return m_edge_softening; }
  BND_File3dmThickening&    CreateThickening()    { m_thickening    .EnsureExists(); return m_thickening; }
  BND_File3dmCurvePiping&   CreateCurvePiping()   { m_curve_piping  .EnsureExists(); return m_curve_piping; }
  BND_File3dmShutLining&    CreateShutLining()    { m_shutlining    .EnsureExists(); return m_shutlining; }
};
