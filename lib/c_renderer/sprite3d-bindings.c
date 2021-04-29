#include <mruby.h>
#include <string.h>
#include <assert.h>
#include <mruby/string.h>
#include <mruby/data.h>
#include <dragonruby.h>
#include "lib/c_renderer/sprite3d-bridge.h"

// MRuby `typedef`s mrb_int in the mruby/value.h
// Then `#define`s mrb_int in mruby.h
// We need to undo the macro and avoid it's usage
// FIXME: I'm surely doing something wrong
#ifdef mrb_int
#undef mrb_int
#endif

void *(*drb_symbol_lookup)(const char *sym) = NULL;

static void (*drb_free_foreign_object_f)(mrb_state *, void *);
static struct RClass *(*mrb_module_get_f)(mrb_state *, const char *);
static mrb_int (*mrb_get_args_f)(mrb_state *, mrb_args_format, ...);
static struct RClass *(*mrb_module_get_under_f)(mrb_state *, struct RClass *, const char *);
static struct RClass *(*mrb_class_get_under_f)(mrb_state *, struct RClass *, const char *);
static struct RClass *(*mrb_define_module_under_f)(mrb_state *, struct RClass *, const char *);
static void (*mrb_define_module_function_f)(mrb_state *, struct RClass *, const char *, mrb_func_t, mrb_aspec);
static struct RClass *(*mrb_define_class_under_f)(mrb_state *, struct RClass *, const char *, struct RClass *);
static void (*mrb_define_method_f)(mrb_state *, struct RClass *, const char *, mrb_func_t, mrb_aspec);
static void (*mrb_define_class_method_f)(mrb_state *, struct RClass *, const char *, mrb_func_t, mrb_aspec);
static struct RData *(*mrb_data_object_alloc_f)(mrb_state *, struct RClass *, void *, const mrb_data_type *);
static mrb_value (*mrb_str_new_cstr_f)(mrb_state *, const char *);
static void (*mrb_raise_f)(mrb_state *, struct RClass *, const char *);
static struct RClass *(*mrb_exc_get_f)(mrb_state *, const char *);
static void drb_free_foreign_object_indirect(mrb_state *state, void *pointer) {
    drb_free_foreign_object_f(state, pointer);
}
struct drb_foreign_object_ZTSPFviE {
    drb_foreign_object_kind kind;
    void (*value)(int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFviE = {"Function_0*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFviE_FromRuby(mrb_state *state, mrb_value self))(int) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPFviE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFviE_ToRuby(mrb_state *state, void (*value)(int)) {
    struct drb_foreign_object_ZTSPFviE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Function_0Pointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPFviE);
    return mrb_obj_value(rdata);
}
static int drb_ffi__ZTSi_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSi_ToRuby(mrb_state *state, int value) {
    return mrb_fixnum_value(value);
}
static id_t drb_ffi__ZTSj_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSj_ToRuby(mrb_state *state, id_t value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSP6rlimit {
    drb_foreign_object_kind kind;
    struct rlimit *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP6rlimit = {"rlimit*", drb_free_foreign_object_indirect};
static struct rlimit *drb_ffi__ZTSP6rlimit_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSP6rlimit *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP6rlimit_ToRuby(mrb_state *state, struct rlimit *value) {
    struct drb_foreign_object_ZTSP6rlimit *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6rlimit));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "RlimitPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSP6rlimit);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP6rusage {
    drb_foreign_object_kind kind;
    struct rusage *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP6rusage = {"rusage*", drb_free_foreign_object_indirect};
static struct rusage *drb_ffi__ZTSP6rusage_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSP6rusage *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP6rusage_ToRuby(mrb_state *state, struct rusage *value) {
    struct drb_foreign_object_ZTSP6rusage *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6rusage));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "RusagePointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSP6rusage);
    return mrb_obj_value(rdata);
}
static __uint16_t drb_ffi__ZTSt_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSt_ToRuby(mrb_state *state, __uint16_t value) {
    return mrb_fixnum_value(value);
}
static __uint64_t drb_ffi__ZTSy_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSy_ToRuby(mrb_state *state, __uint64_t value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPi {
    drb_foreign_object_kind kind;
    int *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPi = {"int*", drb_free_foreign_object_indirect};
static int *drb_ffi__ZTSPi_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPi *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPi_ToRuby(mrb_state *state, int *value) {
    struct drb_foreign_object_ZTSPi *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPi));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "IntPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPi);
    return mrb_obj_value(rdata);
}
static idtype_t drb_ffi__ZTS8idtype_t_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTS8idtype_t_ToRuby(mrb_state *state, idtype_t value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSP9__siginfo {
    drb_foreign_object_kind kind;
    siginfo_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP9__siginfo = {"__siginfo*", drb_free_foreign_object_indirect};
static siginfo_t *drb_ffi__ZTSP9__siginfo_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSP9__siginfo *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP9__siginfo_ToRuby(mrb_state *state, siginfo_t *value) {
    struct drb_foreign_object_ZTSP9__siginfo *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP9__siginfo));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "__siginfoPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSP9__siginfo);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPv {
    drb_foreign_object_kind kind;
    void *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPv = {"void*", drb_free_foreign_object_indirect};
static void *drb_ffi__ZTSPv_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPv *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPv_ToRuby(mrb_state *state, void *value) {
    struct drb_foreign_object_ZTSPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPv));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "VoidPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPv);
    return mrb_obj_value(rdata);
}
static size_t drb_ffi__ZTSm_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSm_ToRuby(mrb_state *state, size_t value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPPv {
    drb_foreign_object_kind kind;
    void **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPv = {"void**", drb_free_foreign_object_indirect};
static void **drb_ffi__ZTSPPv_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPPv *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPv_ToRuby(mrb_state *state, void **value) {
    struct drb_foreign_object_ZTSPPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPv));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "VoidPointerPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPPv);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvvE {
    drb_foreign_object_kind kind;
    void (*value)(void);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvvE = {"Function_1*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvvE_FromRuby(mrb_state *state, mrb_value self))(void) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPFvvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvvE_ToRuby(mrb_state *state, void (*value)(void)) {
    struct drb_foreign_object_ZTSPFvvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Function_1Pointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPFvvE);
    return mrb_obj_value(rdata);
}
static double drb_ffi__ZTSd_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_float(self);
}
static mrb_value drb_ffi__ZTSd_ToRuby(mrb_state *state, double value) {
    return mrb_float_value(state, value);
}
struct drb_foreign_object_ZTSPc {
    drb_foreign_object_kind kind;
    char *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPc = {"char*", drb_free_foreign_object_indirect};
static char *drb_ffi__ZTSPc_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    if (mrb_type(self) == MRB_TT_STRING)
        return RSTRING_PTR(self);
    return ((struct drb_foreign_object_ZTSPc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPc_ToRuby(mrb_state *state, char *value) {
    struct drb_foreign_object_ZTSPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "CharPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPc);
    return mrb_obj_value(rdata);
}
static long drb_ffi__ZTSl_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSl_ToRuby(mrb_state *state, long value) {
    return mrb_fixnum_value(value);
}
static long long drb_ffi__ZTSx_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSx_ToRuby(mrb_state *state, long long value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPFiPKvS0_E {
    drb_foreign_object_kind kind;
    int (*value)(const void *, const void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPKvS0_E = {"Function_2*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPKvS0_E_FromRuby(mrb_state *state, mrb_value self))(const void *, const void *) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPFiPKvS0_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPKvS0_E_ToRuby(mrb_state *state, int (*value)(const void *, const void *)) {
    struct drb_foreign_object_ZTSPFiPKvS0_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPKvS0_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Function_2Pointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPFiPKvS0_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS5div_t {
    drb_foreign_object_kind kind;
    div_t value;
};
static mrb_data_type ForeignObjectType_ZTS5div_t = {"", drb_free_foreign_object_indirect};
static div_t drb_ffi__ZTS5div_t_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS5div_t *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS5div_t_ToRuby(mrb_state *state, div_t value) {
    struct drb_foreign_object_ZTS5div_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS5div_t));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS5div_t);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS6ldiv_t {
    drb_foreign_object_kind kind;
    ldiv_t value;
};
static mrb_data_type ForeignObjectType_ZTS6ldiv_t = {"", drb_free_foreign_object_indirect};
static ldiv_t drb_ffi__ZTS6ldiv_t_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS6ldiv_t *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS6ldiv_t_ToRuby(mrb_state *state, ldiv_t value) {
    struct drb_foreign_object_ZTS6ldiv_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6ldiv_t));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS6ldiv_t);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS7lldiv_t {
    drb_foreign_object_kind kind;
    lldiv_t value;
};
static mrb_data_type ForeignObjectType_ZTS7lldiv_t = {"", drb_free_foreign_object_indirect};
static lldiv_t drb_ffi__ZTS7lldiv_t_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS7lldiv_t *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS7lldiv_t_ToRuby(mrb_state *state, lldiv_t value) {
    struct drb_foreign_object_ZTS7lldiv_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS7lldiv_t));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS7lldiv_t);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPPc {
    drb_foreign_object_kind kind;
    char **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPc = {"char**", drb_free_foreign_object_indirect};
static char **drb_ffi__ZTSPPc_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPPc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPc_ToRuby(mrb_state *state, char **value) {
    struct drb_foreign_object_ZTSPPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "CharPointerPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPPc);
    return mrb_obj_value(rdata);
}
static float drb_ffi__ZTSf_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_float(self);
}
static mrb_value drb_ffi__ZTSf_ToRuby(mrb_state *state, float value) {
    return mrb_float_value(state, value);
}
static long double drb_ffi__ZTSe_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_float(self);
}
static mrb_value drb_ffi__ZTSe_ToRuby(mrb_state *state, long double value) {
    return mrb_float_value(state, value);
}
struct drb_foreign_object_ZTSPt {
    drb_foreign_object_kind kind;
    unsigned short *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPt = {"unsigned short*", drb_free_foreign_object_indirect};
static unsigned short *drb_ffi__ZTSPt_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPt *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPt_ToRuby(mrb_state *state, unsigned short *value) {
    struct drb_foreign_object_ZTSPt *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPt));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Unsigned_shortPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPt);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPj {
    drb_foreign_object_kind kind;
    unsigned int *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPj = {"unsigned int*", drb_free_foreign_object_indirect};
static unsigned int *drb_ffi__ZTSPj_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPj *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPj_ToRuby(mrb_state *state, unsigned int *value) {
    struct drb_foreign_object_ZTSPj *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPj));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Unsigned_intPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPj);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPh {
    drb_foreign_object_kind kind;
    unsigned char *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPh = {"unsigned char*", drb_free_foreign_object_indirect};
static unsigned char *drb_ffi__ZTSPh_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    if (mrb_type(self) == MRB_TT_STRING)
        return RSTRING_PTR(self);
    return ((struct drb_foreign_object_ZTSPh *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPh_ToRuby(mrb_state *state, unsigned char *value) {
    struct drb_foreign_object_ZTSPh *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPh));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Unsigned_charPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPh);
    return mrb_obj_value(rdata);
}
static void (^ _Nonnull drb_ffi__ZTSU13block_pointerFvvE_FromRuby(mrb_state *state, mrb_value self))(void) {
}
static mrb_value drb_ffi__ZTSU13block_pointerFvvE_ToRuby(mrb_state *state, void (^ _Nonnull value)(void)) {
}
static int (^ _Nonnull drb_ffi__ZTSU13block_pointerFiPKvS0_E_FromRuby(mrb_state *state, mrb_value self))(const void *, const void *) {
}
static mrb_value drb_ffi__ZTSU13block_pointerFiPKvS0_E_ToRuby(mrb_state *state, int (^ _Nonnull value)(const void *, const void *)) {
}
struct drb_foreign_object_ZTSPl {
    drb_foreign_object_kind kind;
    long *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPl = {"long*", drb_free_foreign_object_indirect};
static long *drb_ffi__ZTSPl_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPl *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPl_ToRuby(mrb_state *state, long *value) {
    struct drb_foreign_object_ZTSPl *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPl));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "LongPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPl);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPd {
    drb_foreign_object_kind kind;
    double *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPd = {"double*", drb_free_foreign_object_indirect};
static double *drb_ffi__ZTSPd_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPd *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPd_ToRuby(mrb_state *state, double *value) {
    struct drb_foreign_object_ZTSPd *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPd));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "DoublePointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPd);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiPvPKvS1_E {
    drb_foreign_object_kind kind;
    int (*value)(void *, const void *, const void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPvPKvS1_E = {"Function_3*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPvPKvS1_E_FromRuby(mrb_state *state, mrb_value self))(void *, const void *, const void *) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPFiPvPKvS1_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPvPKvS1_E_ToRuby(mrb_state *state, int (*value)(void *, const void *, const void *)) {
    struct drb_foreign_object_ZTSPFiPvPKvS1_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPvPKvS1_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Function_3Pointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPFiPvPKvS1_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPPh {
    drb_foreign_object_kind kind;
    unsigned char **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPh = {"unsigned char**", drb_free_foreign_object_indirect};
static unsigned char **drb_ffi__ZTSPPh_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPPh *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPh_ToRuby(mrb_state *state, unsigned char **value) {
    struct drb_foreign_object_ZTSPPh *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPh));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Unsigned_charPointerPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPPh);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP7SCamera {
    drb_foreign_object_kind kind;
    SCamera *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP7SCamera = {"SCamera*", drb_free_foreign_object_indirect};
static SCamera *drb_ffi__ZTSP7SCamera_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSP7SCamera *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP7SCamera_ToRuby(mrb_state *state, SCamera *value) {
    struct drb_foreign_object_ZTSP7SCamera *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP7SCamera));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "SCameraPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSP7SCamera);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPf {
    drb_foreign_object_kind kind;
    float *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPf = {"float*", drb_free_foreign_object_indirect};
static float *drb_ffi__ZTSPf_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    return ((struct drb_foreign_object_ZTSPf *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPf_ToRuby(mrb_state *state, float *value) {
    struct drb_foreign_object_ZTSPf *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPf));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "FloatPointer");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTSPf);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS6rlimit {
    drb_foreign_object_kind kind;
    struct rlimit value;
};
static mrb_data_type ForeignObjectType_ZTS6rlimit = {"rlimit", drb_free_foreign_object_indirect};
static struct rlimit drb_ffi__ZTS6rlimit_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS6rlimit *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS6rlimit_ToRuby(mrb_state *state, struct rlimit value) {
    struct drb_foreign_object_ZTS6rlimit *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6rlimit));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Rlimit");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS6rlimit);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS6rusage {
    drb_foreign_object_kind kind;
    struct rusage value;
};
static mrb_data_type ForeignObjectType_ZTS6rusage = {"rusage", drb_free_foreign_object_indirect};
static struct rusage drb_ffi__ZTS6rusage_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS6rusage_ToRuby(mrb_state *state, struct rusage value) {
    struct drb_foreign_object_ZTS6rusage *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6rusage));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Rusage");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS6rusage);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS9__siginfo {
    drb_foreign_object_kind kind;
    siginfo_t value;
};
static mrb_data_type ForeignObjectType_ZTS9__siginfo = {"__siginfo", drb_free_foreign_object_indirect};
static siginfo_t drb_ffi__ZTS9__siginfo_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS9__siginfo_ToRuby(mrb_state *state, siginfo_t value) {
    struct drb_foreign_object_ZTS9__siginfo *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS9__siginfo));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "__siginfo");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS9__siginfo);
    return mrb_obj_value(rdata);
}
static char drb_ffi__ZTSc_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSc_ToRuby(mrb_state *state, char value) {
    return mrb_fixnum_value(value);
}
static unsigned char drb_ffi__ZTSh_FromRuby(mrb_state *state, mrb_value self) {
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSh_ToRuby(mrb_state *state, unsigned char value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTS7SCamera {
    drb_foreign_object_kind kind;
    SCamera value;
};
static mrb_data_type ForeignObjectType_ZTS7SCamera = {"SCamera", drb_free_foreign_object_indirect};
static SCamera drb_ffi__ZTS7SCamera_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS7SCamera *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS7SCamera_ToRuby(mrb_state *state, SCamera value) {
    struct drb_foreign_object_ZTS7SCamera *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS7SCamera));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "SCamera");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS7SCamera);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS7timeval {
    drb_foreign_object_kind kind;
    struct timeval value;
};
static mrb_data_type ForeignObjectType_ZTS7timeval = {"timeval", drb_free_foreign_object_indirect};
static struct timeval drb_ffi__ZTS7timeval_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS7timeval *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS7timeval_ToRuby(mrb_state *state, struct timeval value) {
    struct drb_foreign_object_ZTS7timeval *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS7timeval));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Timeval");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS7timeval);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS6sigval {
    drb_foreign_object_kind kind;
    union sigval value;
};
static mrb_data_type ForeignObjectType_ZTS6sigval = {"sigval", drb_free_foreign_object_indirect};
static union sigval drb_ffi__ZTS6sigval_FromRuby(mrb_state *state, mrb_value self) {
    return ((struct drb_foreign_object_ZTS6sigval *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS6sigval_ToRuby(mrb_state *state, union sigval value) {
    struct drb_foreign_object_ZTS6sigval *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6sigval));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Sigval");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS6sigval);
    return mrb_obj_value(rdata);
}
static unsigned long drb_ffi__ZTSA7_m_FromRuby(mrb_state *state, mrb_value self)[7] {
}
static mrb_value drb_ffi__ZTSA7_m_ToRuby(mrb_state *state, unsigned long value[7]) {
}
static float drb_ffi__ZTSA4_f_FromRuby(mrb_state *state, mrb_value self)[4] {
}
static mrb_value drb_ffi__ZTSA4_f_ToRuby(mrb_state *state, float value[4]) {
}
static float drb_ffi__ZTSA4_A4_f_FromRuby(mrb_state *state, mrb_value self)[4][4] {
}
static mrb_value drb_ffi__ZTSA4_A4_f_ToRuby(mrb_state *state, float value[4][4]) {
}
static mrb_value drb_ffi__ZTSPFviE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFviE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (int)));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "Function_0Pointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPFviE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFviE_GetValue(mrb_state *mrb, mrb_value value) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFviE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFviE_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviE_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6rlimit_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP6rlimit *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6rlimit));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct rlimit));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "RlimitPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSP6rlimit);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP6rlimit_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS6rlimit_ToRuby(mrb, *drb_ffi__ZTSP6rlimit_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP6rlimit_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP6rlimit_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP6rlimit_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS6rlimit_ToRuby(mrb, drb_ffi__ZTSP6rlimit_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP6rlimit_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct rlimit new_value = drb_ffi__ZTS6rlimit_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP6rlimit_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6rusage_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP6rusage *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6rusage));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct rusage));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "RusagePointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSP6rusage);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP6rusage_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS6rusage_ToRuby(mrb, *drb_ffi__ZTSP6rusage_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP6rusage_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP6rusage_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP6rusage_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS6rusage_ToRuby(mrb, drb_ffi__ZTSP6rusage_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP6rusage_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct rusage new_value = drb_ffi__ZTS6rusage_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP6rusage_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPi_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPi *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPi));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "IntPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPi);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPi_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSi_ToRuby(mrb, *drb_ffi__ZTSPi_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPi_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPi_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPi_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSi_ToRuby(mrb, drb_ffi__ZTSPi_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPi_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    int new_value = drb_ffi__ZTSi_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPi_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP9__siginfo_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP9__siginfo *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP9__siginfo));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(siginfo_t));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "__siginfoPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSP9__siginfo);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP9__siginfo_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS9__siginfo_ToRuby(mrb, *drb_ffi__ZTSP9__siginfo_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP9__siginfo_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP9__siginfo_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP9__siginfo_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS9__siginfo_ToRuby(mrb, drb_ffi__ZTSP9__siginfo_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP9__siginfo_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    siginfo_t new_value = drb_ffi__ZTS9__siginfo_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP9__siginfo_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPPv_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPv));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void *));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "VoidPointerPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPPv);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPv_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPv_ToRuby(mrb, *drb_ffi__ZTSPPv_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPv_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPv_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPv_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPv_ToRuby(mrb, drb_ffi__ZTSPPv_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPv_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    void *new_value = drb_ffi__ZTSPv_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPv_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void)));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "Function_1Pointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPFvvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvvE_GetValue(mrb_state *mrb, mrb_value value) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvvE_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPc_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPc));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(char));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "CharPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPc);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPc_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSc_ToRuby(mrb, *drb_ffi__ZTSPc_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPc_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPc_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPc_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSc_ToRuby(mrb, drb_ffi__ZTSPc_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPc_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    char new_value = drb_ffi__ZTSc_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPc_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPc_GetString(mrb_state *state, mrb_value self) {
    return mrb_str_new_cstr_f(state, drb_ffi__ZTSPc_FromRuby(state, self));
}
static mrb_value drb_ffi__ZTSPFiPKvS0_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPKvS0_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPKvS0_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (const void *, const void *)));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "Function_2Pointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPKvS0_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPKvS0_E_GetValue(mrb_state *mrb, mrb_value value) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPKvS0_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPKvS0_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPKvS0_E_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPKvS0_E_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPPc_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPc));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(char *));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "CharPointerPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPPc);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPc_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPc_ToRuby(mrb, *drb_ffi__ZTSPPc_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPc_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPc_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPc_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPc_ToRuby(mrb, drb_ffi__ZTSPPc_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPc_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    char *new_value = drb_ffi__ZTSPc_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPc_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPt_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPt *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPt));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(unsigned short));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "Unsigned_shortPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPt);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPt_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSt_ToRuby(mrb, *drb_ffi__ZTSPt_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPt_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPt_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPt_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSt_ToRuby(mrb, drb_ffi__ZTSPt_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPt_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    unsigned short new_value = drb_ffi__ZTSt_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPt_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPj_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPj *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPj));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(unsigned int));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "Unsigned_intPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPj);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPj_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSj_ToRuby(mrb, *drb_ffi__ZTSPj_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPj_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPj_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPj_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSj_ToRuby(mrb, drb_ffi__ZTSPj_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPj_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    unsigned int new_value = drb_ffi__ZTSj_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPj_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPh_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPh *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPh));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(unsigned char));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "Unsigned_charPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPh);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPh_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSh_ToRuby(mrb, *drb_ffi__ZTSPh_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPh_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPh_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPh_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSh_ToRuby(mrb, drb_ffi__ZTSPh_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPh_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    unsigned char new_value = drb_ffi__ZTSh_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPh_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPh_GetString(mrb_state *state, mrb_value self) {
    return mrb_str_new_cstr_f(state, drb_ffi__ZTSPh_FromRuby(state, self));
}
static mrb_value drb_ffi__ZTSPl_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPl *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPl));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(long));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "LongPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPl);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPl_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSl_ToRuby(mrb, *drb_ffi__ZTSPl_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPl_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPl_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPl_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSl_ToRuby(mrb, drb_ffi__ZTSPl_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPl_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    long new_value = drb_ffi__ZTSl_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPl_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPd_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPd *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPd));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(double));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "DoublePointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPd);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPd_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSd_ToRuby(mrb, *drb_ffi__ZTSPd_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPd_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPd_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPd_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSd_ToRuby(mrb, drb_ffi__ZTSPd_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPd_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    double new_value = drb_ffi__ZTSd_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPd_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvPKvS1_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPvPKvS1_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPvPKvS1_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (void *, const void *, const void *)));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "Function_3Pointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPvPKvS1_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPvPKvS1_E_GetValue(mrb_state *mrb, mrb_value value) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvPKvS1_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPvPKvS1_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPvPKvS1_E_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvPKvS1_E_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_raise_f(mrb, mrb_exc_get_f(mrb, "RuntimeError"), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPPh_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPh *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPh));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(unsigned char *));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "Unsigned_charPointerPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPPh);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPh_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPh_ToRuby(mrb, *drb_ffi__ZTSPPh_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPh_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPh_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPh_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPh_ToRuby(mrb, drb_ffi__ZTSPPh_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPh_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    unsigned char *new_value = drb_ffi__ZTSPh_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPh_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP7SCamera_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP7SCamera *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP7SCamera));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(SCamera));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "SCameraPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSP7SCamera);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP7SCamera_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS7SCamera_ToRuby(mrb, *drb_ffi__ZTSP7SCamera_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP7SCamera_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP7SCamera_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP7SCamera_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS7SCamera_ToRuby(mrb, drb_ffi__ZTSP7SCamera_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP7SCamera_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    SCamera new_value = drb_ffi__ZTS7SCamera_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP7SCamera_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPf_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPf *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPf));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(float));
    ptr->should_free = 1;
    struct RClass *FFI = mrb_module_get_f(mrb, "FFI");
    struct RClass *module = mrb_module_get_under_f(mrb, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(mrb, module, "FloatPointer");
    struct RData *rdata = mrb_data_object_alloc_f(mrb, klass, ptr, &ForeignObjectType_ZTSPf);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPf_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSf_ToRuby(mrb, *drb_ffi__ZTSPf_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPf_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPf_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPf_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSf_ToRuby(mrb, drb_ffi__ZTSPf_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPf_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    float new_value = drb_ffi__ZTSf_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPf_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS5div_t_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS5div_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS5div_t *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS5div_t);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS5div_t_quot_Get(mrb_state *state, mrb_value self) {
    div_t record = drb_ffi__ZTS5div_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.quot);
}
static mrb_value drb_ffi__ZTS5div_t_quot_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS5div_t *)DATA_PTR(self))->value)->quot = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS5div_t_rem_Get(mrb_state *state, mrb_value self) {
    div_t record = drb_ffi__ZTS5div_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.rem);
}
static mrb_value drb_ffi__ZTS5div_t_rem_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS5div_t *)DATA_PTR(self))->value)->rem = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6ldiv_t_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS6ldiv_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6ldiv_t *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS6ldiv_t);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS6ldiv_t_quot_Get(mrb_state *state, mrb_value self) {
    ldiv_t record = drb_ffi__ZTS6ldiv_t_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.quot);
}
static mrb_value drb_ffi__ZTS6ldiv_t_quot_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6ldiv_t *)DATA_PTR(self))->value)->quot = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6ldiv_t_rem_Get(mrb_state *state, mrb_value self) {
    ldiv_t record = drb_ffi__ZTS6ldiv_t_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.rem);
}
static mrb_value drb_ffi__ZTS6ldiv_t_rem_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6ldiv_t *)DATA_PTR(self))->value)->rem = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7lldiv_t_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS7lldiv_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS7lldiv_t *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS7lldiv_t);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS7lldiv_t_quot_Get(mrb_state *state, mrb_value self) {
    lldiv_t record = drb_ffi__ZTS7lldiv_t_FromRuby(state, self);
    return drb_ffi__ZTSx_ToRuby(state, record.quot);
}
static mrb_value drb_ffi__ZTS7lldiv_t_quot_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long long new_value = drb_ffi__ZTSx_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7lldiv_t *)DATA_PTR(self))->value)->quot = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7lldiv_t_rem_Get(mrb_state *state, mrb_value self) {
    lldiv_t record = drb_ffi__ZTS7lldiv_t_FromRuby(state, self);
    return drb_ffi__ZTSx_ToRuby(state, record.rem);
}
static mrb_value drb_ffi__ZTS7lldiv_t_rem_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long long new_value = drb_ffi__ZTSx_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7lldiv_t *)DATA_PTR(self))->value)->rem = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rlimit_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS6rlimit *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6rlimit *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Rlimit");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS6rlimit);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS6rlimit_rlim_cur_Get(mrb_state *state, mrb_value self) {
    struct rlimit record = drb_ffi__ZTS6rlimit_FromRuby(state, self);
    return drb_ffi__ZTSy_ToRuby(state, record.rlim_cur);
}
static mrb_value drb_ffi__ZTS6rlimit_rlim_cur_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    rlim_t new_value = drb_ffi__ZTSy_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rlimit *)DATA_PTR(self))->value)->rlim_cur = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rlimit_rlim_max_Get(mrb_state *state, mrb_value self) {
    struct rlimit record = drb_ffi__ZTS6rlimit_FromRuby(state, self);
    return drb_ffi__ZTSy_ToRuby(state, record.rlim_max);
}
static mrb_value drb_ffi__ZTS6rlimit_rlim_max_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    rlim_t new_value = drb_ffi__ZTSy_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rlimit *)DATA_PTR(self))->value)->rlim_max = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS6rusage *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6rusage *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Rusage");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS6rusage);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS6rusage_ru_utime_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTS7timeval_ToRuby(state, record.ru_utime);
}
static mrb_value drb_ffi__ZTS6rusage_ru_utime_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    struct timeval new_value = drb_ffi__ZTS7timeval_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_utime = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_stime_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTS7timeval_ToRuby(state, record.ru_stime);
}
static mrb_value drb_ffi__ZTS6rusage_ru_stime_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    struct timeval new_value = drb_ffi__ZTS7timeval_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_stime = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_maxrss_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_maxrss);
}
static mrb_value drb_ffi__ZTS6rusage_ru_maxrss_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_maxrss = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_ixrss_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_ixrss);
}
static mrb_value drb_ffi__ZTS6rusage_ru_ixrss_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_ixrss = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_idrss_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_idrss);
}
static mrb_value drb_ffi__ZTS6rusage_ru_idrss_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_idrss = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_isrss_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_isrss);
}
static mrb_value drb_ffi__ZTS6rusage_ru_isrss_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_isrss = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_minflt_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_minflt);
}
static mrb_value drb_ffi__ZTS6rusage_ru_minflt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_minflt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_majflt_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_majflt);
}
static mrb_value drb_ffi__ZTS6rusage_ru_majflt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_majflt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_nswap_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_nswap);
}
static mrb_value drb_ffi__ZTS6rusage_ru_nswap_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_nswap = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_inblock_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_inblock);
}
static mrb_value drb_ffi__ZTS6rusage_ru_inblock_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_inblock = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_oublock_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_oublock);
}
static mrb_value drb_ffi__ZTS6rusage_ru_oublock_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_oublock = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_msgsnd_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_msgsnd);
}
static mrb_value drb_ffi__ZTS6rusage_ru_msgsnd_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_msgsnd = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_msgrcv_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_msgrcv);
}
static mrb_value drb_ffi__ZTS6rusage_ru_msgrcv_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_msgrcv = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_nsignals_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_nsignals);
}
static mrb_value drb_ffi__ZTS6rusage_ru_nsignals_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_nsignals = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_nvcsw_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_nvcsw);
}
static mrb_value drb_ffi__ZTS6rusage_ru_nvcsw_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_nvcsw = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6rusage_ru_nivcsw_Get(mrb_state *state, mrb_value self) {
    struct rusage record = drb_ffi__ZTS6rusage_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.ru_nivcsw);
}
static mrb_value drb_ffi__ZTS6rusage_ru_nivcsw_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6rusage *)DATA_PTR(self))->value)->ru_nivcsw = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS9__siginfo *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS9__siginfo *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "__siginfo");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS9__siginfo);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_signo_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.si_signo);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_signo_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_signo = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_si_errno_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.si_errno);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_errno_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_errno = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_si_code_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.si_code);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_code_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_code = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_si_pid_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.si_pid);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_pid_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    pid_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_pid = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_si_uid_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSj_ToRuby(state, record.si_uid);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_uid_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    uid_t new_value = drb_ffi__ZTSj_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_uid = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_si_status_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.si_status);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_status_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_status = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_si_addr_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSPv_ToRuby(state, record.si_addr);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_addr_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *new_value = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_addr = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_si_value_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTS6sigval_ToRuby(state, record.si_value);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_value_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    union sigval new_value = drb_ffi__ZTS6sigval_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_value = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo_si_band_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.si_band);
}
static mrb_value drb_ffi__ZTS9__siginfo_si_band_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->si_band = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9__siginfo___pad_Get(mrb_state *state, mrb_value self) {
    siginfo_t record = drb_ffi__ZTS9__siginfo_FromRuby(state, self);
    return drb_ffi__ZTSA7_m_ToRuby(state, record.__pad);
}
static mrb_value drb_ffi__ZTS9__siginfo___pad_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned long new_value[7] = drb_ffi__ZTSA7_m_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9__siginfo *)DATA_PTR(self))->value)->__pad = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7SCamera_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS7SCamera *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS7SCamera *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "SCamera");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS7SCamera);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS7SCamera_position_Get(mrb_state *state, mrb_value self) {
    SCamera record = drb_ffi__ZTS7SCamera_FromRuby(state, self);
    return drb_ffi__ZTSA4_f_ToRuby(state, record.position);
}
static mrb_value drb_ffi__ZTS7SCamera_position_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    float new_value[4] = drb_ffi__ZTSA4_f_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7SCamera *)DATA_PTR(self))->value)->position = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7SCamera_forward_Get(mrb_state *state, mrb_value self) {
    SCamera record = drb_ffi__ZTS7SCamera_FromRuby(state, self);
    return drb_ffi__ZTSA4_f_ToRuby(state, record.forward);
}
static mrb_value drb_ffi__ZTS7SCamera_forward_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    float new_value[4] = drb_ffi__ZTSA4_f_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7SCamera *)DATA_PTR(self))->value)->forward = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7SCamera_right_Get(mrb_state *state, mrb_value self) {
    SCamera record = drb_ffi__ZTS7SCamera_FromRuby(state, self);
    return drb_ffi__ZTSA4_f_ToRuby(state, record.right);
}
static mrb_value drb_ffi__ZTS7SCamera_right_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    float new_value[4] = drb_ffi__ZTSA4_f_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7SCamera *)DATA_PTR(self))->value)->right = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7SCamera_up_Get(mrb_state *state, mrb_value self) {
    SCamera record = drb_ffi__ZTS7SCamera_FromRuby(state, self);
    return drb_ffi__ZTSA4_f_ToRuby(state, record.up);
}
static mrb_value drb_ffi__ZTS7SCamera_up_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    float new_value[4] = drb_ffi__ZTSA4_f_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7SCamera *)DATA_PTR(self))->value)->up = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7SCamera_view_matrix_Get(mrb_state *state, mrb_value self) {
    SCamera record = drb_ffi__ZTS7SCamera_FromRuby(state, self);
    return drb_ffi__ZTSA4_A4_f_ToRuby(state, record.view_matrix);
}
static mrb_value drb_ffi__ZTS7SCamera_view_matrix_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    float new_value[4][4] = drb_ffi__ZTSA4_A4_f_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7SCamera *)DATA_PTR(self))->value)->view_matrix = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7SCamera_view_matrix_status_Get(mrb_state *state, mrb_value self) {
    SCamera record = drb_ffi__ZTS7SCamera_FromRuby(state, self);
    return drb_ffi__ZTSh_ToRuby(state, record.view_matrix_status);
}
static mrb_value drb_ffi__ZTS7SCamera_view_matrix_status_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    uint8_t new_value = drb_ffi__ZTSh_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7SCamera *)DATA_PTR(self))->value)->view_matrix_status = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7timeval_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS7timeval *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS7timeval *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Timeval");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS7timeval);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS7timeval_tv_sec_Get(mrb_state *state, mrb_value self) {
    struct timeval record = drb_ffi__ZTS7timeval_FromRuby(state, self);
    return drb_ffi__ZTSl_ToRuby(state, record.tv_sec);
}
static mrb_value drb_ffi__ZTS7timeval_tv_sec_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    __darwin_time_t new_value = drb_ffi__ZTSl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7timeval *)DATA_PTR(self))->value)->tv_sec = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7timeval_tv_usec_Get(mrb_state *state, mrb_value self) {
    struct timeval record = drb_ffi__ZTS7timeval_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.tv_usec);
}
static mrb_value drb_ffi__ZTS7timeval_tv_usec_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    __darwin_suseconds_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7timeval *)DATA_PTR(self))->value)->tv_usec = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6sigval_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS6sigval *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6sigval *));
    struct RClass *FFI = mrb_module_get_f(state, "FFI");
    struct RClass *module = mrb_module_get_under_f(state, FFI, "Sprite3D_C");
    struct RClass *klass = mrb_class_get_under_f(state, module, "Sigval");
    struct RData *rdata = mrb_data_object_alloc_f(state, klass, ptr, &ForeignObjectType_ZTS6sigval);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS6sigval_sival_int_Get(mrb_state *state, mrb_value self) {
    union sigval record = drb_ffi__ZTS6sigval_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.sival_int);
}
static mrb_value drb_ffi__ZTS6sigval_sival_int_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6sigval *)DATA_PTR(self))->value)->sival_int = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6sigval_sival_ptr_Get(mrb_state *state, mrb_value self) {
    union sigval record = drb_ffi__ZTS6sigval_FromRuby(state, self);
    return drb_ffi__ZTSPv_ToRuby(state, record.sival_ptr);
}
static mrb_value drb_ffi__ZTS6sigval_sival_ptr_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *new_value = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6sigval *)DATA_PTR(self))->value)->sival_ptr = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi_signal_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    void (*_1)(int) = drb_ffi__ZTSPFviE_FromRuby(state, args[1]);
    void (*ret_val)(int) = signal(_0, _1);
    return drb_ffi__ZTSPFviE_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getpriority_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    id_t _1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = getpriority(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getiopolicy_np_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = getiopolicy_np(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getrlimit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    struct rlimit *_1 = drb_ffi__ZTSP6rlimit_FromRuby(state, args[1]);
    int ret_val = getrlimit(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getrusage_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    struct rusage *_1 = drb_ffi__ZTSP6rusage_FromRuby(state, args[1]);
    int ret_val = getrusage(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_setpriority_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    id_t _1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = setpriority(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_setiopolicy_np_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = setiopolicy_np(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_setrlimit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    struct rlimit *_1 = drb_ffi__ZTSP6rlimit_FromRuby(state, args[1]);
    int ret_val = setrlimit(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi__OSSwapInt16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    __uint16_t _data_0 = drb_ffi__ZTSt_FromRuby(state, args[0]);
    __uint16_t ret_val = _OSSwapInt16(_data_0);
    return drb_ffi__ZTSt_ToRuby(state, ret_val);
}
static mrb_value drb_ffi__OSSwapInt32_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    __uint32_t _data_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    __uint32_t ret_val = _OSSwapInt32(_data_0);
    return drb_ffi__ZTSj_ToRuby(state, ret_val);
}
static mrb_value drb_ffi__OSSwapInt64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    __uint64_t _data_0 = drb_ffi__ZTSy_FromRuby(state, args[0]);
    __uint64_t ret_val = _OSSwapInt64(_data_0);
    return drb_ffi__ZTSy_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_wait_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int *_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    pid_t ret_val = wait(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_waitpid_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    pid_t _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    pid_t ret_val = waitpid(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_waitid_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    idtype_t _0 = drb_ffi__ZTS8idtype_t_FromRuby(state, args[0]);
    id_t _1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    siginfo_t *_2 = drb_ffi__ZTSP9__siginfo_FromRuby(state, args[2]);
    int _3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    int ret_val = waitid(_0, _1, _2, _3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_wait3_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int *_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    struct rusage *_2 = drb_ffi__ZTSP6rusage_FromRuby(state, args[2]);
    pid_t ret_val = wait3(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_wait4_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    pid_t _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    struct rusage *_3 = drb_ffi__ZTSP6rusage_FromRuby(state, args[3]);
    pid_t ret_val = wait4(_0, _1, _2, _3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_alloca_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    size_t _0 = drb_ffi__ZTSm_FromRuby(state, args[0]);
    void *ret_val = alloca(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_malloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    size_t __size_0 = drb_ffi__ZTSm_FromRuby(state, args[0]);
    void *ret_val = malloc(__size_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_calloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    size_t __count_0 = drb_ffi__ZTSm_FromRuby(state, args[0]);
    size_t __size_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    void *ret_val = calloc(__count_0, __size_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_free_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    free(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_realloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__ptr_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __size_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    void *ret_val = realloc(__ptr_0, __size_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_valloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    size_t _0 = drb_ffi__ZTSm_FromRuby(state, args[0]);
    void *ret_val = valloc(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_aligned_alloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    size_t __alignment_0 = drb_ffi__ZTSm_FromRuby(state, args[0]);
    size_t __size_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    void *ret_val = aligned_alloc(__alignment_0, __size_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_posix_memalign_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void **__memptr_0 = drb_ffi__ZTSPPv_FromRuby(state, args[0]);
    size_t __alignment_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __size_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    int ret_val = posix_memalign(__memptr_0, __alignment_1, __size_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_abort_Binding(mrb_state *state, mrb_value value) {
    abort();
    return mrb_nil_value();
}
static mrb_value drb_ffi_abs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = abs(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_atexit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void (*_0)(void) = drb_ffi__ZTSPFvvE_FromRuby(state, args[0]);
    int ret_val = atexit(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_atof_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    double ret_val = atof(_0);
    return drb_ffi__ZTSd_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_atoi_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = atoi(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_atol_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    long ret_val = atol(_0);
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_atoll_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    long long ret_val = atoll(_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bsearch_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__key_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    void *__base_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    size_t __nel_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    size_t __width_3 = drb_ffi__ZTSm_FromRuby(state, args[3]);
    int (*__compar_4)(const void *, const void *) = drb_ffi__ZTSPFiPKvS0_E_FromRuby(state, args[4]);
    void *ret_val = bsearch(__key_0, __base_1, __nel_2, __width_3, __compar_4);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_div_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    div_t ret_val = div(_0, _1);
    return drb_ffi__ZTS5div_t_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_exit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    exit(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_getenv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *ret_val = getenv(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_labs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long _0 = drb_ffi__ZTSl_FromRuby(state, args[0]);
    long ret_val = labs(_0);
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_ldiv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long _0 = drb_ffi__ZTSl_FromRuby(state, args[0]);
    long _1 = drb_ffi__ZTSl_FromRuby(state, args[1]);
    ldiv_t ret_val = ldiv(_0, _1);
    return drb_ffi__ZTS6ldiv_t_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_llabs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long long _0 = drb_ffi__ZTSx_FromRuby(state, args[0]);
    long long ret_val = llabs(_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_lldiv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long long _0 = drb_ffi__ZTSx_FromRuby(state, args[0]);
    long long _1 = drb_ffi__ZTSx_FromRuby(state, args[1]);
    lldiv_t ret_val = lldiv(_0, _1);
    return drb_ffi__ZTS7lldiv_t_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mblen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *__s_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    size_t __n_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    int ret_val = mblen(__s_0, __n_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mbstowcs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    wchar_t *_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    size_t _2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    size_t ret_val = mbstowcs(_0, _1, _2);
    return drb_ffi__ZTSm_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mbtowc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    wchar_t *_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    size_t _2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    int ret_val = mbtowc(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_qsort_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    int (*__compar_3)(const void *, const void *) = drb_ffi__ZTSPFiPKvS0_E_FromRuby(state, args[3]);
    qsort(__base_0, __nel_1, __width_2, __compar_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_rand_Binding(mrb_state *state, mrb_value value) {
    int ret_val = rand();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_srand_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned int _0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    srand(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_strtod_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    double ret_val = strtod(_0, _1);
    return drb_ffi__ZTSd_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_strtof_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    float ret_val = strtof(_0, _1);
    return drb_ffi__ZTSf_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_strtol_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *__str_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **__endptr_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int __base_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    long ret_val = strtol(__str_0, __endptr_1, __base_2);
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_strtold_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    long double ret_val = strtold(_0, _1);
    return drb_ffi__ZTSe_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_strtoll_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *__str_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **__endptr_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int __base_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    long long ret_val = strtoll(__str_0, __endptr_1, __base_2);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_strtoul_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *__str_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **__endptr_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int __base_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    unsigned long ret_val = strtoul(__str_0, __endptr_1, __base_2);
    return drb_ffi__ZTSm_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_strtoull_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *__str_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **__endptr_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int __base_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    unsigned long long ret_val = strtoull(__str_0, __endptr_1, __base_2);
    return drb_ffi__ZTSy_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_system_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = system(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_wcstombs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    wchar_t *_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    size_t _2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    size_t ret_val = wcstombs(_0, _1, _2);
    return drb_ffi__ZTSm_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_wctomb_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    wchar_t _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = wctomb(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi__Exit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    _Exit(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_a64l_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    long ret_val = a64l(_0);
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_drand48_Binding(mrb_state *state, mrb_value value) {
    double ret_val = drand48();
    return drb_ffi__ZTSd_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_ecvt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    double _0 = drb_ffi__ZTSd_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int *_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    int *_3 = drb_ffi__ZTSPi_FromRuby(state, args[3]);
    char *ret_val = ecvt(_0, _1, _2, _3);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_erand48_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned short *_0 = drb_ffi__ZTSPt_FromRuby(state, args[0]);
    double ret_val = erand48(_0);
    return drb_ffi__ZTSd_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fcvt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    double _0 = drb_ffi__ZTSd_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int *_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    int *_3 = drb_ffi__ZTSPi_FromRuby(state, args[3]);
    char *ret_val = fcvt(_0, _1, _2, _3);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gcvt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    double _0 = drb_ffi__ZTSd_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    char *ret_val = gcvt(_0, _1, _2);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getsubopt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char **_0 = drb_ffi__ZTSPPc_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    char **_2 = drb_ffi__ZTSPPc_FromRuby(state, args[2]);
    int ret_val = getsubopt(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_grantpt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = grantpt(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_initstate_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned int _0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    size_t _2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    char *ret_val = initstate(_0, _1, _2);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_jrand48_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned short *_0 = drb_ffi__ZTSPt_FromRuby(state, args[0]);
    long ret_val = jrand48(_0);
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_l64a_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long _0 = drb_ffi__ZTSl_FromRuby(state, args[0]);
    char *ret_val = l64a(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_lcong48_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned short *_0 = drb_ffi__ZTSPt_FromRuby(state, args[0]);
    lcong48(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_lrand48_Binding(mrb_state *state, mrb_value value) {
    long ret_val = lrand48();
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mktemp_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *ret_val = mktemp(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mkstemp_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = mkstemp(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrand48_Binding(mrb_state *state, mrb_value value) {
    long ret_val = mrand48();
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_nrand48_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned short *_0 = drb_ffi__ZTSPt_FromRuby(state, args[0]);
    long ret_val = nrand48(_0);
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_posix_openpt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = posix_openpt(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_ptsname_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    char *ret_val = ptsname(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_ptsname_r_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int fildes_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    char *buffer_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    size_t buflen_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    int ret_val = ptsname_r(fildes_0, buffer_1, buflen_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_putenv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = putenv(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_random_Binding(mrb_state *state, mrb_value value) {
    long ret_val = random();
    return drb_ffi__ZTSl_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rand_r_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned int *_0 = drb_ffi__ZTSPj_FromRuby(state, args[0]);
    int ret_val = rand_r(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_realpath_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *ret_val = realpath(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_seed48_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned short *_0 = drb_ffi__ZTSPt_FromRuby(state, args[0]);
    unsigned short *ret_val = seed48(_0);
    return drb_ffi__ZTSPt_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_setenv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *__name_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *__value_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int __overwrite_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = setenv(__name_0, __value_1, __overwrite_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_setkey_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    setkey(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_setstate_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *ret_val = setstate(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_srand48_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    long _0 = drb_ffi__ZTSl_FromRuby(state, args[0]);
    srand48(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_srandom_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned int _0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    srandom(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_unlockpt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = unlockpt(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_unsetenv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = unsetenv(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_arc4random_Binding(mrb_state *state, mrb_value value) {
    uint32_t ret_val = arc4random();
    return drb_ffi__ZTSj_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_arc4random_addrandom_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned char *_0 = drb_ffi__ZTSPh_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    arc4random_addrandom(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_arc4random_buf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__buf_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nbytes_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    arc4random_buf(__buf_0, __nbytes_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_arc4random_stir_Binding(mrb_state *state, mrb_value value) {
    arc4random_stir();
    return mrb_nil_value();
}
static mrb_value drb_ffi_arc4random_uniform_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    uint32_t __upper_bound_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    uint32_t ret_val = arc4random_uniform(__upper_bound_0);
    return drb_ffi__ZTSj_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_atexit_b_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void (^ _Nonnull _0)(void) = drb_ffi__ZTSU13block_pointerFvvE_FromRuby(state, args[0]);
    int ret_val = atexit_b(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bsearch_b_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__key_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    void *__base_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    size_t __nel_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    size_t __width_3 = drb_ffi__ZTSm_FromRuby(state, args[3]);
    int (^ _Nonnull __compar_4)(const void *, const void *) = drb_ffi__ZTSU13block_pointerFiPKvS0_E_FromRuby(state, args[4]);
    void *ret_val = bsearch_b(__key_0, __base_1, __nel_2, __width_3, __compar_4);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetcap_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    char *ret_val = cgetcap(_0, _1, _2);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetclose_Binding(mrb_state *state, mrb_value value) {
    int ret_val = cgetclose();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetent_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char **_0 = drb_ffi__ZTSPPc_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    char *_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    int ret_val = cgetent(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetfirst_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char **_0 = drb_ffi__ZTSPPc_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int ret_val = cgetfirst(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetmatch_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = cgetmatch(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetnext_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char **_0 = drb_ffi__ZTSPPc_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int ret_val = cgetnext(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetnum_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    long *_2 = drb_ffi__ZTSPl_FromRuby(state, args[2]);
    int ret_val = cgetnum(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetset_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = cgetset(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetstr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char **_2 = drb_ffi__ZTSPPc_FromRuby(state, args[2]);
    int ret_val = cgetstr(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_cgetustr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char **_2 = drb_ffi__ZTSPPc_FromRuby(state, args[2]);
    int ret_val = cgetustr(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_daemon_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = daemon(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_devname_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    dev_t _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    mode_t _1 = drb_ffi__ZTSt_FromRuby(state, args[1]);
    char *ret_val = devname(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_devname_r_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    dev_t _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    mode_t _1 = drb_ffi__ZTSt_FromRuby(state, args[1]);
    char *buf_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    int len_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    char *ret_val = devname_r(_0, _1, buf_2, len_3);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getbsize_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    int *_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    long *_1 = drb_ffi__ZTSPl_FromRuby(state, args[1]);
    char *ret_val = getbsize(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getloadavg_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    double *_0 = drb_ffi__ZTSPd_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = getloadavg(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getprogname_Binding(mrb_state *state, mrb_value value) {
    char *ret_val = getprogname();
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_setprogname_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    setprogname(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_heapsort_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    int (*__compar_3)(const void *, const void *) = drb_ffi__ZTSPFiPKvS0_E_FromRuby(state, args[3]);
    int ret_val = heapsort(__base_0, __nel_1, __width_2, __compar_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_heapsort_b_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    __sort_noescape int (^__compar_3)(const void *, const void *) = drb_ffi__ZTSU13block_pointerFiPKvS0_E_FromRuby(state, args[3]);
    int ret_val = heapsort_b(__base_0, __nel_1, __width_2, __compar_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mergesort_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    int (*__compar_3)(const void *, const void *) = drb_ffi__ZTSPFiPKvS0_E_FromRuby(state, args[3]);
    int ret_val = mergesort(__base_0, __nel_1, __width_2, __compar_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mergesort_b_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    __sort_noescape int (^__compar_3)(const void *, const void *) = drb_ffi__ZTSU13block_pointerFiPKvS0_E_FromRuby(state, args[3]);
    int ret_val = mergesort_b(__base_0, __nel_1, __width_2, __compar_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_psort_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    int (*__compar_3)(const void *, const void *) = drb_ffi__ZTSPFiPKvS0_E_FromRuby(state, args[3]);
    psort(__base_0, __nel_1, __width_2, __compar_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_psort_b_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    __sort_noescape int (^__compar_3)(const void *, const void *) = drb_ffi__ZTSU13block_pointerFiPKvS0_E_FromRuby(state, args[3]);
    psort_b(__base_0, __nel_1, __width_2, __compar_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_psort_r_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    void *_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int (*__compar_4)(void *, const void *, const void *) = drb_ffi__ZTSPFiPvPKvS1_E_FromRuby(state, args[4]);
    psort_r(__base_0, __nel_1, __width_2, _3, __compar_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_qsort_b_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    __sort_noescape int (^__compar_3)(const void *, const void *) = drb_ffi__ZTSU13block_pointerFiPKvS0_E_FromRuby(state, args[3]);
    qsort_b(__base_0, __nel_1, __width_2, __compar_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_qsort_r_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__base_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __nel_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    size_t __width_2 = drb_ffi__ZTSm_FromRuby(state, args[2]);
    void *_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int (*__compar_4)(void *, const void *, const void *) = drb_ffi__ZTSPFiPvPKvS1_E_FromRuby(state, args[4]);
    qsort_r(__base_0, __nel_1, __width_2, _3, __compar_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_radixsort_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned char **__base_0 = drb_ffi__ZTSPPh_FromRuby(state, args[0]);
    int __nel_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    unsigned char *__table_2 = drb_ffi__ZTSPh_FromRuby(state, args[2]);
    unsigned int __endbyte_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = radixsort(__base_0, __nel_1, __table_2, __endbyte_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rpmatch_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = rpmatch(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sradixsort_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    unsigned char **__base_0 = drb_ffi__ZTSPPh_FromRuby(state, args[0]);
    int __nel_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    unsigned char *__table_2 = drb_ffi__ZTSPh_FromRuby(state, args[2]);
    unsigned int __endbyte_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = sradixsort(__base_0, __nel_1, __table_2, __endbyte_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sranddev_Binding(mrb_state *state, mrb_value value) {
    sranddev();
    return mrb_nil_value();
}
static mrb_value drb_ffi_srandomdev_Binding(mrb_state *state, mrb_value value) {
    srandomdev();
    return mrb_nil_value();
}
static mrb_value drb_ffi_reallocf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    void *__ptr_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    size_t __size_1 = drb_ffi__ZTSm_FromRuby(state, args[1]);
    void *ret_val = reallocf(__ptr_0, __size_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_strtoq_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *__str_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **__endptr_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int __base_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    long long ret_val = strtoq(__str_0, __endptr_1, __base_2);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_strtouq_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    char *__str_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **__endptr_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int __base_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    unsigned long long ret_val = strtouq(__str_0, __endptr_1, __base_2);
    return drb_ffi__ZTSy_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bridge_new_camera_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    mrb_get_args_f(state, "*", &args, &argc);
    float *p_0 = drb_ffi__ZTSPf_FromRuby(state, args[0]);
    float *f_1 = drb_ffi__ZTSPf_FromRuby(state, args[1]);
    float *u_2 = drb_ffi__ZTSPf_FromRuby(state, args[2]);
    SCamera *ret_val = bridge_new_camera(p_0, f_1, u_2);
    return drb_ffi__ZTSP7SCamera_ToRuby(state, ret_val);
}
static int drb_ffi_init_indirect_functions(void *(*lookup)(const char *));
DRB_FFI_EXPORT
void drb_register_c_extensions(void *(*lookup)(const char *), mrb_state *state, struct RClass *FFI) {
    if (drb_ffi_init_indirect_functions(lookup))
        return;
    struct RClass *module = mrb_define_module_under_f(state, FFI, "Sprite3D_C");
    struct RClass *object_class = state->object_class;
    mrb_define_module_function_f(state, module, "signal", drb_ffi_signal_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "getpriority", drb_ffi_getpriority_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "getiopolicy_np", drb_ffi_getiopolicy_np_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "getrlimit", drb_ffi_getrlimit_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "getrusage", drb_ffi_getrusage_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "setpriority", drb_ffi_setpriority_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "setiopolicy_np", drb_ffi_setiopolicy_np_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "setrlimit", drb_ffi_setrlimit_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "_OSSwapInt16", drb_ffi__OSSwapInt16_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "_OSSwapInt32", drb_ffi__OSSwapInt32_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "_OSSwapInt64", drb_ffi__OSSwapInt64_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "wait", drb_ffi_wait_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "waitpid", drb_ffi_waitpid_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "waitid", drb_ffi_waitid_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "wait3", drb_ffi_wait3_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "wait4", drb_ffi_wait4_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "alloca", drb_ffi_alloca_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "malloc", drb_ffi_malloc_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "calloc", drb_ffi_calloc_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "free", drb_ffi_free_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "realloc", drb_ffi_realloc_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "valloc", drb_ffi_valloc_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "aligned_alloc", drb_ffi_aligned_alloc_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "posix_memalign", drb_ffi_posix_memalign_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "abort", drb_ffi_abort_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "abs", drb_ffi_abs_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "atexit", drb_ffi_atexit_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "atof", drb_ffi_atof_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "atoi", drb_ffi_atoi_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "atol", drb_ffi_atol_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "atoll", drb_ffi_atoll_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "bsearch", drb_ffi_bsearch_Binding, MRB_ARGS_REQ(5));
    mrb_define_module_function_f(state, module, "div", drb_ffi_div_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "exit", drb_ffi_exit_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "getenv", drb_ffi_getenv_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "labs", drb_ffi_labs_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "ldiv", drb_ffi_ldiv_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "llabs", drb_ffi_llabs_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "lldiv", drb_ffi_lldiv_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "mblen", drb_ffi_mblen_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "mbstowcs", drb_ffi_mbstowcs_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "mbtowc", drb_ffi_mbtowc_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "qsort", drb_ffi_qsort_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "rand", drb_ffi_rand_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "srand", drb_ffi_srand_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "strtod", drb_ffi_strtod_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "strtof", drb_ffi_strtof_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "strtol", drb_ffi_strtol_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "strtold", drb_ffi_strtold_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "strtoll", drb_ffi_strtoll_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "strtoul", drb_ffi_strtoul_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "strtoull", drb_ffi_strtoull_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "system", drb_ffi_system_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "wcstombs", drb_ffi_wcstombs_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "wctomb", drb_ffi_wctomb_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "_Exit", drb_ffi__Exit_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "a64l", drb_ffi_a64l_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "drand48", drb_ffi_drand48_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "ecvt", drb_ffi_ecvt_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "erand48", drb_ffi_erand48_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "fcvt", drb_ffi_fcvt_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "gcvt", drb_ffi_gcvt_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "getsubopt", drb_ffi_getsubopt_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "grantpt", drb_ffi_grantpt_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "initstate", drb_ffi_initstate_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "jrand48", drb_ffi_jrand48_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "l64a", drb_ffi_l64a_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "lcong48", drb_ffi_lcong48_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "lrand48", drb_ffi_lrand48_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "mktemp", drb_ffi_mktemp_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "mkstemp", drb_ffi_mkstemp_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "mrand48", drb_ffi_mrand48_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "nrand48", drb_ffi_nrand48_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "posix_openpt", drb_ffi_posix_openpt_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "ptsname", drb_ffi_ptsname_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "ptsname_r", drb_ffi_ptsname_r_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "putenv", drb_ffi_putenv_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "random", drb_ffi_random_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "rand_r", drb_ffi_rand_r_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "realpath", drb_ffi_realpath_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "seed48", drb_ffi_seed48_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "setenv", drb_ffi_setenv_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "setkey", drb_ffi_setkey_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "setstate", drb_ffi_setstate_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "srand48", drb_ffi_srand48_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "srandom", drb_ffi_srandom_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "unlockpt", drb_ffi_unlockpt_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "unsetenv", drb_ffi_unsetenv_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "arc4random", drb_ffi_arc4random_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "arc4random_addrandom", drb_ffi_arc4random_addrandom_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "arc4random_buf", drb_ffi_arc4random_buf_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "arc4random_stir", drb_ffi_arc4random_stir_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "arc4random_uniform", drb_ffi_arc4random_uniform_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "atexit_b", drb_ffi_atexit_b_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "bsearch_b", drb_ffi_bsearch_b_Binding, MRB_ARGS_REQ(5));
    mrb_define_module_function_f(state, module, "cgetcap", drb_ffi_cgetcap_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "cgetclose", drb_ffi_cgetclose_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "cgetent", drb_ffi_cgetent_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "cgetfirst", drb_ffi_cgetfirst_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "cgetmatch", drb_ffi_cgetmatch_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "cgetnext", drb_ffi_cgetnext_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "cgetnum", drb_ffi_cgetnum_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "cgetset", drb_ffi_cgetset_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "cgetstr", drb_ffi_cgetstr_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "cgetustr", drb_ffi_cgetustr_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "daemon", drb_ffi_daemon_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "devname", drb_ffi_devname_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "devname_r", drb_ffi_devname_r_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "getbsize", drb_ffi_getbsize_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "getloadavg", drb_ffi_getloadavg_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "getprogname", drb_ffi_getprogname_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "setprogname", drb_ffi_setprogname_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "heapsort", drb_ffi_heapsort_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "heapsort_b", drb_ffi_heapsort_b_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "mergesort", drb_ffi_mergesort_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "mergesort_b", drb_ffi_mergesort_b_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "psort", drb_ffi_psort_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "psort_b", drb_ffi_psort_b_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "psort_r", drb_ffi_psort_r_Binding, MRB_ARGS_REQ(5));
    mrb_define_module_function_f(state, module, "qsort_b", drb_ffi_qsort_b_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "qsort_r", drb_ffi_qsort_r_Binding, MRB_ARGS_REQ(5));
    mrb_define_module_function_f(state, module, "radixsort", drb_ffi_radixsort_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "rpmatch", drb_ffi_rpmatch_Binding, MRB_ARGS_REQ(1));
    mrb_define_module_function_f(state, module, "sradixsort", drb_ffi_sradixsort_Binding, MRB_ARGS_REQ(4));
    mrb_define_module_function_f(state, module, "sranddev", drb_ffi_sranddev_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "srandomdev", drb_ffi_srandomdev_Binding, MRB_ARGS_REQ(0));
    mrb_define_module_function_f(state, module, "reallocf", drb_ffi_reallocf_Binding, MRB_ARGS_REQ(2));
    mrb_define_module_function_f(state, module, "strtoq", drb_ffi_strtoq_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "strtouq", drb_ffi_strtouq_Binding, MRB_ARGS_REQ(3));
    mrb_define_module_function_f(state, module, "bridge_new_camera", drb_ffi_bridge_new_camera_Binding, MRB_ARGS_REQ(3));
    struct RClass *Function_0PointerClass = mrb_define_class_under_f(state, module, "Function_0Pointer", object_class);
    mrb_define_class_method_f(state, Function_0PointerClass, "new", drb_ffi__ZTSPFviE_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Function_0PointerClass, "value", drb_ffi__ZTSPFviE_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Function_0PointerClass, "[]", drb_ffi__ZTSPFviE_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Function_0PointerClass, "[]=", drb_ffi__ZTSPFviE_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, Function_0PointerClass, "nil?", drb_ffi__ZTSPFviE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RlimitPointerClass = mrb_define_class_under_f(state, module, "RlimitPointer", object_class);
    mrb_define_class_method_f(state, RlimitPointerClass, "new", drb_ffi__ZTSP6rlimit_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RlimitPointerClass, "value", drb_ffi__ZTSP6rlimit_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RlimitPointerClass, "[]", drb_ffi__ZTSP6rlimit_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RlimitPointerClass, "[]=", drb_ffi__ZTSP6rlimit_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, RlimitPointerClass, "nil?", drb_ffi__ZTSP6rlimit_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RusagePointerClass = mrb_define_class_under_f(state, module, "RusagePointer", object_class);
    mrb_define_class_method_f(state, RusagePointerClass, "new", drb_ffi__ZTSP6rusage_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusagePointerClass, "value", drb_ffi__ZTSP6rusage_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusagePointerClass, "[]", drb_ffi__ZTSP6rusage_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusagePointerClass, "[]=", drb_ffi__ZTSP6rusage_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, RusagePointerClass, "nil?", drb_ffi__ZTSP6rusage_IsNil, MRB_ARGS_REQ(0));
    struct RClass *IntPointerClass = mrb_define_class_under_f(state, module, "IntPointer", object_class);
    mrb_define_class_method_f(state, IntPointerClass, "new", drb_ffi__ZTSPi_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, IntPointerClass, "value", drb_ffi__ZTSPi_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, IntPointerClass, "[]", drb_ffi__ZTSPi_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, IntPointerClass, "[]=", drb_ffi__ZTSPi_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, IntPointerClass, "nil?", drb_ffi__ZTSPi_IsNil, MRB_ARGS_REQ(0));
    struct RClass *__siginfoPointerClass = mrb_define_class_under_f(state, module, "__siginfoPointer", object_class);
    mrb_define_class_method_f(state, __siginfoPointerClass, "new", drb_ffi__ZTSP9__siginfo_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoPointerClass, "value", drb_ffi__ZTSP9__siginfo_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoPointerClass, "[]", drb_ffi__ZTSP9__siginfo_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoPointerClass, "[]=", drb_ffi__ZTSP9__siginfo_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, __siginfoPointerClass, "nil?", drb_ffi__ZTSP9__siginfo_IsNil, MRB_ARGS_REQ(0));
    struct RClass *VoidPointerClass = mrb_define_class_under_f(state, module, "VoidPointer", object_class);
    struct RClass *VoidPointerPointerClass = mrb_define_class_under_f(state, module, "VoidPointerPointer", object_class);
    mrb_define_class_method_f(state, VoidPointerPointerClass, "new", drb_ffi__ZTSPPv_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, VoidPointerPointerClass, "value", drb_ffi__ZTSPPv_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, VoidPointerPointerClass, "[]", drb_ffi__ZTSPPv_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, VoidPointerPointerClass, "[]=", drb_ffi__ZTSPPv_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, VoidPointerPointerClass, "nil?", drb_ffi__ZTSPPv_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_1PointerClass = mrb_define_class_under_f(state, module, "Function_1Pointer", object_class);
    mrb_define_class_method_f(state, Function_1PointerClass, "new", drb_ffi__ZTSPFvvE_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Function_1PointerClass, "value", drb_ffi__ZTSPFvvE_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Function_1PointerClass, "[]", drb_ffi__ZTSPFvvE_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Function_1PointerClass, "[]=", drb_ffi__ZTSPFvvE_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, Function_1PointerClass, "nil?", drb_ffi__ZTSPFvvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *CharPointerClass = mrb_define_class_under_f(state, module, "CharPointer", object_class);
    mrb_define_class_method_f(state, CharPointerClass, "new", drb_ffi__ZTSPc_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, CharPointerClass, "value", drb_ffi__ZTSPc_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, CharPointerClass, "[]", drb_ffi__ZTSPc_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, CharPointerClass, "[]=", drb_ffi__ZTSPc_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, CharPointerClass, "nil?", drb_ffi__ZTSPc_IsNil, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, CharPointerClass, "str", drb_ffi__ZTSPc_GetString, MRB_ARGS_REQ(0));
    struct RClass *Function_2PointerClass = mrb_define_class_under_f(state, module, "Function_2Pointer", object_class);
    mrb_define_class_method_f(state, Function_2PointerClass, "new", drb_ffi__ZTSPFiPKvS0_E_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Function_2PointerClass, "value", drb_ffi__ZTSPFiPKvS0_E_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Function_2PointerClass, "[]", drb_ffi__ZTSPFiPKvS0_E_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Function_2PointerClass, "[]=", drb_ffi__ZTSPFiPKvS0_E_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, Function_2PointerClass, "nil?", drb_ffi__ZTSPFiPKvS0_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *CharPointerPointerClass = mrb_define_class_under_f(state, module, "CharPointerPointer", object_class);
    mrb_define_class_method_f(state, CharPointerPointerClass, "new", drb_ffi__ZTSPPc_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, CharPointerPointerClass, "value", drb_ffi__ZTSPPc_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, CharPointerPointerClass, "[]", drb_ffi__ZTSPPc_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, CharPointerPointerClass, "[]=", drb_ffi__ZTSPPc_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, CharPointerPointerClass, "nil?", drb_ffi__ZTSPPc_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Unsigned_shortPointerClass = mrb_define_class_under_f(state, module, "Unsigned_shortPointer", object_class);
    mrb_define_class_method_f(state, Unsigned_shortPointerClass, "new", drb_ffi__ZTSPt_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_shortPointerClass, "value", drb_ffi__ZTSPt_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_shortPointerClass, "[]", drb_ffi__ZTSPt_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Unsigned_shortPointerClass, "[]=", drb_ffi__ZTSPt_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, Unsigned_shortPointerClass, "nil?", drb_ffi__ZTSPt_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Unsigned_intPointerClass = mrb_define_class_under_f(state, module, "Unsigned_intPointer", object_class);
    mrb_define_class_method_f(state, Unsigned_intPointerClass, "new", drb_ffi__ZTSPj_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_intPointerClass, "value", drb_ffi__ZTSPj_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_intPointerClass, "[]", drb_ffi__ZTSPj_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Unsigned_intPointerClass, "[]=", drb_ffi__ZTSPj_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, Unsigned_intPointerClass, "nil?", drb_ffi__ZTSPj_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Unsigned_charPointerClass = mrb_define_class_under_f(state, module, "Unsigned_charPointer", object_class);
    mrb_define_class_method_f(state, Unsigned_charPointerClass, "new", drb_ffi__ZTSPh_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_charPointerClass, "value", drb_ffi__ZTSPh_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_charPointerClass, "[]", drb_ffi__ZTSPh_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Unsigned_charPointerClass, "[]=", drb_ffi__ZTSPh_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, Unsigned_charPointerClass, "nil?", drb_ffi__ZTSPh_IsNil, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_charPointerClass, "str", drb_ffi__ZTSPh_GetString, MRB_ARGS_REQ(0));
    struct RClass *LongPointerClass = mrb_define_class_under_f(state, module, "LongPointer", object_class);
    mrb_define_class_method_f(state, LongPointerClass, "new", drb_ffi__ZTSPl_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, LongPointerClass, "value", drb_ffi__ZTSPl_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, LongPointerClass, "[]", drb_ffi__ZTSPl_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, LongPointerClass, "[]=", drb_ffi__ZTSPl_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, LongPointerClass, "nil?", drb_ffi__ZTSPl_IsNil, MRB_ARGS_REQ(0));
    struct RClass *DoublePointerClass = mrb_define_class_under_f(state, module, "DoublePointer", object_class);
    mrb_define_class_method_f(state, DoublePointerClass, "new", drb_ffi__ZTSPd_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, DoublePointerClass, "value", drb_ffi__ZTSPd_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, DoublePointerClass, "[]", drb_ffi__ZTSPd_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, DoublePointerClass, "[]=", drb_ffi__ZTSPd_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, DoublePointerClass, "nil?", drb_ffi__ZTSPd_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_3PointerClass = mrb_define_class_under_f(state, module, "Function_3Pointer", object_class);
    mrb_define_class_method_f(state, Function_3PointerClass, "new", drb_ffi__ZTSPFiPvPKvS1_E_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Function_3PointerClass, "value", drb_ffi__ZTSPFiPvPKvS1_E_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Function_3PointerClass, "[]", drb_ffi__ZTSPFiPvPKvS1_E_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Function_3PointerClass, "[]=", drb_ffi__ZTSPFiPvPKvS1_E_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, Function_3PointerClass, "nil?", drb_ffi__ZTSPFiPvPKvS1_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Unsigned_charPointerPointerClass = mrb_define_class_under_f(state, module, "Unsigned_charPointerPointer", object_class);
    mrb_define_class_method_f(state, Unsigned_charPointerPointerClass, "new", drb_ffi__ZTSPPh_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_charPointerPointerClass, "value", drb_ffi__ZTSPPh_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Unsigned_charPointerPointerClass, "[]", drb_ffi__ZTSPPh_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Unsigned_charPointerPointerClass, "[]=", drb_ffi__ZTSPPh_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, Unsigned_charPointerPointerClass, "nil?", drb_ffi__ZTSPPh_IsNil, MRB_ARGS_REQ(0));
    struct RClass *SCameraPointerClass = mrb_define_class_under_f(state, module, "SCameraPointer", object_class);
    mrb_define_class_method_f(state, SCameraPointerClass, "new", drb_ffi__ZTSP7SCamera_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraPointerClass, "value", drb_ffi__ZTSP7SCamera_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraPointerClass, "[]", drb_ffi__ZTSP7SCamera_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, SCameraPointerClass, "[]=", drb_ffi__ZTSP7SCamera_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, SCameraPointerClass, "nil?", drb_ffi__ZTSP7SCamera_IsNil, MRB_ARGS_REQ(0));
    struct RClass *FloatPointerClass = mrb_define_class_under_f(state, module, "FloatPointer", object_class);
    mrb_define_class_method_f(state, FloatPointerClass, "new", drb_ffi__ZTSPf_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, FloatPointerClass, "value", drb_ffi__ZTSPf_GetValue, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, FloatPointerClass, "[]", drb_ffi__ZTSPf_GetAt, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, FloatPointerClass, "[]=", drb_ffi__ZTSPf_SetAt, MRB_ARGS_REQ(2));
    mrb_define_method_f(state, FloatPointerClass, "nil?", drb_ffi__ZTSPf_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Class = mrb_define_class_under_f(state, module, "", object_class);
    mrb_define_class_method_f(state, Class, "new", drb_ffi__ZTS5div_t_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Class, "quot", drb_ffi__ZTS5div_t_quot_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Class, "quot=", drb_ffi__ZTS5div_t_quot_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, Class, "rem", drb_ffi__ZTS5div_t_rem_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, Class, "rem=", drb_ffi__ZTS5div_t_rem_Set, MRB_ARGS_REQ(1));
    struct RClass *RlimitClass = mrb_define_class_under_f(state, module, "Rlimit", object_class);
    mrb_define_class_method_f(state, RlimitClass, "new", drb_ffi__ZTS6rlimit_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RlimitClass, "rlim_cur", drb_ffi__ZTS6rlimit_rlim_cur_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RlimitClass, "rlim_cur=", drb_ffi__ZTS6rlimit_rlim_cur_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RlimitClass, "rlim_max", drb_ffi__ZTS6rlimit_rlim_max_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RlimitClass, "rlim_max=", drb_ffi__ZTS6rlimit_rlim_max_Set, MRB_ARGS_REQ(1));
    struct RClass *RusageClass = mrb_define_class_under_f(state, module, "Rusage", object_class);
    mrb_define_class_method_f(state, RusageClass, "new", drb_ffi__ZTS6rusage_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_utime", drb_ffi__ZTS6rusage_ru_utime_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_utime=", drb_ffi__ZTS6rusage_ru_utime_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_stime", drb_ffi__ZTS6rusage_ru_stime_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_stime=", drb_ffi__ZTS6rusage_ru_stime_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_maxrss", drb_ffi__ZTS6rusage_ru_maxrss_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_maxrss=", drb_ffi__ZTS6rusage_ru_maxrss_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_ixrss", drb_ffi__ZTS6rusage_ru_ixrss_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_ixrss=", drb_ffi__ZTS6rusage_ru_ixrss_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_idrss", drb_ffi__ZTS6rusage_ru_idrss_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_idrss=", drb_ffi__ZTS6rusage_ru_idrss_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_isrss", drb_ffi__ZTS6rusage_ru_isrss_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_isrss=", drb_ffi__ZTS6rusage_ru_isrss_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_minflt", drb_ffi__ZTS6rusage_ru_minflt_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_minflt=", drb_ffi__ZTS6rusage_ru_minflt_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_majflt", drb_ffi__ZTS6rusage_ru_majflt_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_majflt=", drb_ffi__ZTS6rusage_ru_majflt_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_nswap", drb_ffi__ZTS6rusage_ru_nswap_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_nswap=", drb_ffi__ZTS6rusage_ru_nswap_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_inblock", drb_ffi__ZTS6rusage_ru_inblock_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_inblock=", drb_ffi__ZTS6rusage_ru_inblock_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_oublock", drb_ffi__ZTS6rusage_ru_oublock_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_oublock=", drb_ffi__ZTS6rusage_ru_oublock_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_msgsnd", drb_ffi__ZTS6rusage_ru_msgsnd_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_msgsnd=", drb_ffi__ZTS6rusage_ru_msgsnd_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_msgrcv", drb_ffi__ZTS6rusage_ru_msgrcv_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_msgrcv=", drb_ffi__ZTS6rusage_ru_msgrcv_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_nsignals", drb_ffi__ZTS6rusage_ru_nsignals_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_nsignals=", drb_ffi__ZTS6rusage_ru_nsignals_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_nvcsw", drb_ffi__ZTS6rusage_ru_nvcsw_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_nvcsw=", drb_ffi__ZTS6rusage_ru_nvcsw_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, RusageClass, "ru_nivcsw", drb_ffi__ZTS6rusage_ru_nivcsw_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, RusageClass, "ru_nivcsw=", drb_ffi__ZTS6rusage_ru_nivcsw_Set, MRB_ARGS_REQ(1));
    struct RClass *__siginfoClass = mrb_define_class_under_f(state, module, "__siginfo", object_class);
    mrb_define_class_method_f(state, __siginfoClass, "new", drb_ffi__ZTS9__siginfo_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_signo", drb_ffi__ZTS9__siginfo_si_signo_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_signo=", drb_ffi__ZTS9__siginfo_si_signo_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "si_errno", drb_ffi__ZTS9__siginfo_si_errno_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_errno=", drb_ffi__ZTS9__siginfo_si_errno_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "si_code", drb_ffi__ZTS9__siginfo_si_code_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_code=", drb_ffi__ZTS9__siginfo_si_code_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "si_pid", drb_ffi__ZTS9__siginfo_si_pid_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_pid=", drb_ffi__ZTS9__siginfo_si_pid_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "si_uid", drb_ffi__ZTS9__siginfo_si_uid_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_uid=", drb_ffi__ZTS9__siginfo_si_uid_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "si_status", drb_ffi__ZTS9__siginfo_si_status_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_status=", drb_ffi__ZTS9__siginfo_si_status_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "si_addr", drb_ffi__ZTS9__siginfo_si_addr_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_addr=", drb_ffi__ZTS9__siginfo_si_addr_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "si_value", drb_ffi__ZTS9__siginfo_si_value_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_value=", drb_ffi__ZTS9__siginfo_si_value_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "si_band", drb_ffi__ZTS9__siginfo_si_band_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "si_band=", drb_ffi__ZTS9__siginfo_si_band_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, __siginfoClass, "__pad", drb_ffi__ZTS9__siginfo___pad_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, __siginfoClass, "__pad=", drb_ffi__ZTS9__siginfo___pad_Set, MRB_ARGS_REQ(1));
    struct RClass *SCameraClass = mrb_define_class_under_f(state, module, "SCamera", object_class);
    mrb_define_class_method_f(state, SCameraClass, "new", drb_ffi__ZTS7SCamera_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraClass, "position", drb_ffi__ZTS7SCamera_position_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraClass, "position=", drb_ffi__ZTS7SCamera_position_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, SCameraClass, "forward", drb_ffi__ZTS7SCamera_forward_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraClass, "forward=", drb_ffi__ZTS7SCamera_forward_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, SCameraClass, "right", drb_ffi__ZTS7SCamera_right_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraClass, "right=", drb_ffi__ZTS7SCamera_right_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, SCameraClass, "up", drb_ffi__ZTS7SCamera_up_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraClass, "up=", drb_ffi__ZTS7SCamera_up_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, SCameraClass, "view_matrix", drb_ffi__ZTS7SCamera_view_matrix_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraClass, "view_matrix=", drb_ffi__ZTS7SCamera_view_matrix_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, SCameraClass, "view_matrix_status", drb_ffi__ZTS7SCamera_view_matrix_status_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SCameraClass, "view_matrix_status=", drb_ffi__ZTS7SCamera_view_matrix_status_Set, MRB_ARGS_REQ(1));
    struct RClass *TimevalClass = mrb_define_class_under_f(state, module, "Timeval", object_class);
    mrb_define_class_method_f(state, TimevalClass, "new", drb_ffi__ZTS7timeval_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, TimevalClass, "tv_sec", drb_ffi__ZTS7timeval_tv_sec_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, TimevalClass, "tv_sec=", drb_ffi__ZTS7timeval_tv_sec_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, TimevalClass, "tv_usec", drb_ffi__ZTS7timeval_tv_usec_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, TimevalClass, "tv_usec=", drb_ffi__ZTS7timeval_tv_usec_Set, MRB_ARGS_REQ(1));
    struct RClass *SigvalClass = mrb_define_class_under_f(state, module, "Sigval", object_class);
    mrb_define_class_method_f(state, SigvalClass, "new", drb_ffi__ZTS6sigval_New, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SigvalClass, "sival_int", drb_ffi__ZTS6sigval_sival_int_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SigvalClass, "sival_int=", drb_ffi__ZTS6sigval_sival_int_Set, MRB_ARGS_REQ(1));
    mrb_define_method_f(state, SigvalClass, "sival_ptr", drb_ffi__ZTS6sigval_sival_ptr_Get, MRB_ARGS_REQ(0));
    mrb_define_method_f(state, SigvalClass, "sival_ptr=", drb_ffi__ZTS6sigval_sival_ptr_Set, MRB_ARGS_REQ(1));
}
static int drb_ffi_init_indirect_functions(void *(*lookup)(const char *fnname)) {
  drb_symbol_lookup = lookup;
  if (!(drb_free_foreign_object_f = (void (*)(mrb_state *, void *)) lookup("drb_free_foreign_object"))) return -1;
  if (!(mrb_class_get_under_f = (struct RClass *(*)(mrb_state *, struct RClass *, const char *)) lookup("mrb_class_get_under"))) return -1;
  if (!(mrb_data_object_alloc_f = (struct RData *(*)(mrb_state *, struct RClass *, void *, const mrb_data_type *)) lookup("mrb_data_object_alloc"))) return -1;
  if (!(mrb_define_class_method_f = (void (*)(mrb_state *, struct RClass *, const char *, mrb_func_t, mrb_aspec)) lookup("mrb_define_class_method"))) return -1;
  if (!(mrb_define_class_under_f = (struct RClass *(*)(mrb_state *, struct RClass *, const char *, struct RClass *)) lookup("mrb_define_class_under"))) return -1;
  if (!(mrb_define_method_f = (void (*)(mrb_state *, struct RClass *, const char *, mrb_func_t, mrb_aspec)) lookup("mrb_define_method"))) return -1;
  if (!(mrb_define_module_function_f = (void (*)(mrb_state *, struct RClass *, const char *, mrb_func_t, mrb_aspec)) lookup("mrb_define_module_function"))) return -1;
  if (!(mrb_define_module_under_f = (struct RClass *(*)(mrb_state *, struct RClass *, const char *)) lookup("mrb_define_module_under"))) return -1;
  if (!(mrb_exc_get_f = (struct RClass *(*)(mrb_state *, const char *)) lookup("mrb_exc_get"))) return -1;
  if (!(mrb_get_args_f = (mrb_int (*)(mrb_state *, mrb_args_format, ...)) lookup("mrb_get_args"))) return -1;
  if (!(mrb_module_get_f = (struct RClass *(*)(mrb_state *, const char *)) lookup("mrb_module_get"))) return -1;
  if (!(mrb_module_get_under_f = (struct RClass *(*)(mrb_state *, struct RClass *, const char *)) lookup("mrb_module_get_under"))) return -1;
  if (!(mrb_raise_f = (void (*)(mrb_state *, struct RClass *, const char *)) lookup("mrb_raise"))) return -1;
  if (!(mrb_str_new_cstr_f = (mrb_value (*)(mrb_state *, const char *)) lookup("mrb_str_new_cstr"))) return -1;
  return 0;
}
