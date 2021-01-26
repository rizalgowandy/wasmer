// The Wasmer C/C++ header file compatible with the [`wasm-c-api`]
// standard API, as `wasm.h` (included here).
//
// This file is automatically generated by `lib/c-api/build.rs` of the
// [`wasmer-c-api`] Rust crate.
//
// # Stability
//
// The [`wasm-c-api`] standard API is a _living_ standard. There is no
// commitment for stability yet. We (Wasmer) will try our best to keep
// backward compatibility as much as possible. Nonetheless, some
// necessary API aren't yet standardized, and as such, we provide a
// custom API, e.g. `wasi_*` types and functions.
//
// The documentation makes it clear whether a function is unstable.
// 
// When a type or a function will be deprecated, it will be marked as
// such with the appropriated compiler warning, and will be removed at
// the next release round.
//
// # Documentation
//
// At the time of writing, the [`wasm-c-api`] standard has no
// documentation. This file also does not include inline
// documentation. However, we have made (and we continue to make) an
// important effort to document everything. [See the documentation
// online][documentation]. Please refer to this page for the real
// canonical documentation. It also contains numerous examples.
//
// To generate the documentation locally, run `cargo doc --open` from
// within the [`wasmer-c-api`] Rust crate.
//
// [`wasm-c-api`]: https://github.com/WebAssembly/wasm-c-api
// [`wasmer-c-api`]: https://github.com/wasmerio/wasmer/tree/master/lib/c-api
// [documentation]: https://wasmerio.github.io/wasmer/crates/wasmer_c_api/

#if !defined(WASMER_WASM_H_PRELUDE)

#define WASMER_WASM_H_PRELUDE

// Define the `ARCH_X86_X64` constant.
#if defined(MSVC) && defined(_M_AMD64)
#  define ARCH_X86_64
#elif (defined(GCC) || defined(__GNUC__) || defined(__clang__)) && defined(__x86_64__)
#  define ARCH_X86_64
#endif

// Compatibility with non-Clang compilers.
#if !defined(__has_attribute)
#  define __has_attribute(x) 0
#endif

// Compatibility with non-Clang compilers.
#if !defined(__has_declspec_attribute)
#  define __has_declspec_attribute(x) 0
#endif

// Define the `DEPRECATED` macro.
#if defined(GCC) || defined(__GNUC__) || __has_attribute(deprecated)
#  define DEPRECATED(message) __attribute__((deprecated(message)))
#elif defined(MSVC) || __has_declspec_attribute(deprecated)
#  define DEPRECATED(message) __declspec(deprecated(message))
#endif

// The `jit` feature has been enabled for this build.
#define WASMER_JIT_ENABLED

// The `compiler` feature has been enabled for this build.
#define WASMER_COMPILER_ENABLED

// The `wasi` feature has been enabled for this build.
#define WASMER_WASI_ENABLED

// This file corresponds to the following Wasmer version.
#define WASMER_VERSION "1.0.1"
#define WASMER_VERSION_MAJOR 1
#define WASMER_VERSION_MINOR 0
#define WASMER_VERSION_PATCH 1
#define WASMER_VERSION_PRE ""

#endif // WASMER_WASM_H_PRELUDE


//
// OK, here we go. The code below is automatically generated.
//


#ifndef WASMER_WASM_H
#define WASMER_WASM_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "wasm.h"

#if defined(WASMER_WASI_ENABLED)
typedef enum {
#if defined(WASMER_WASI_ENABLED)
  INVALID_VERSION = -1,
#endif
#if defined(WASMER_WASI_ENABLED)
  LATEST = 0,
#endif
#if defined(WASMER_WASI_ENABLED)
  SNAPSHOT0 = 1,
#endif
#if defined(WASMER_WASI_ENABLED)
  SNAPSHOT1 = 2,
#endif
} wasi_version_t;
#endif

#if defined(WASMER_COMPILER_ENABLED)
typedef enum {
  CRANELIFT = 0,
  LLVM = 1,
  SINGLEPASS = 2,
} wasmer_compiler_t;
#endif

typedef enum {
  JIT = 0,
  NATIVE = 1,
  OBJECT_FILE = 2,
} wasmer_engine_t;

#if defined(WASMER_WASI_ENABLED)
typedef struct wasi_config_t wasi_config_t;
#endif

#if defined(WASMER_WASI_ENABLED)
typedef struct wasi_env_t wasi_env_t;
#endif

#if defined(WASMER_WASI_ENABLED)
typedef struct wasm_named_extern_t wasm_named_extern_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if defined(WASMER_WASI_ENABLED)
void wasi_config_arg(wasi_config_t *config, const char *arg);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_capture_stderr(wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_capture_stdout(wasi_config_t *config);
#endif

/**
 *Represents a vector of `wasm_named_extern_t`.
 *
 *Read the documentation of [`wasm_named_extern_t`] to see more concrete examples.
 */
typedef struct {
  uintptr_t size;
  wasm_named_extern_t **data;
} wasm_named_extern_vec_t;

#if defined(WASMER_WASI_ENABLED)
void wasi_config_arg(wasi_config_t *config, const char *arg);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_env(wasi_config_t *config, const char *key, const char *value);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_inherit_stderr(wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_inherit_stdin(wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_config_inherit_stdout(wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
bool wasi_config_mapdir(wasi_config_t *config, const char *alias, const char *dir);
#endif

#if defined(WASMER_WASI_ENABLED)
wasi_config_t *wasi_config_new(const char *program_name);
#endif

#if defined(WASMER_WASI_ENABLED)
bool wasi_config_preopen_dir(wasi_config_t *config, const char *dir);
#endif

#if defined(WASMER_WASI_ENABLED)
void wasi_env_delete(wasi_env_t *_state);
#endif

#if defined(WASMER_WASI_ENABLED)
wasi_env_t *wasi_env_new(wasi_config_t *config);
#endif

#if defined(WASMER_WASI_ENABLED)
intptr_t wasi_env_read_stderr(wasi_env_t *env, char *buffer, uintptr_t buffer_len);
#endif

#if defined(WASMER_WASI_ENABLED)
intptr_t wasi_env_read_stdout(wasi_env_t *env, char *buffer, uintptr_t buffer_len);
#endif

#if defined(WASMER_WASI_ENABLED)
DEPRECATED("This function is longer necessary. You may safely remove all calls to it and everything will continue to work.")
bool wasi_env_set_instance(wasi_env_t *_env,
                           const wasm_instance_t *_instance);
#endif

#if defined(WASMER_WASI_ENABLED)
DEPRECATED("This function is no longer necessary. You may safely remove all calls to it and everything will continue to work.")
void wasi_env_set_memory(wasi_env_t *_env,
                         const wasm_memory_t *_memory);
#endif

#if defined(WASMER_WASI_ENABLED)
bool wasi_get_imports(const wasm_store_t *store,
                      const wasm_module_t *module,
                      const wasi_env_t *wasi_env,
                      wasm_extern_vec_t *imports);
#endif

#if defined(WASMER_WASI_ENABLED)
wasm_func_t *wasi_get_start_function(wasm_instance_t *instance);
#endif

#if defined(WASMER_WASI_ENABLED)
bool wasi_get_unordered_imports(const wasm_store_t *store,
                                const wasm_module_t *module,
                                const wasi_env_t *wasi_env,
                                wasm_named_extern_vec_t *imports);
#endif

#if defined(WASMER_WASI_ENABLED)
wasi_version_t wasi_get_wasi_version(const wasm_module_t *module);
#endif

#if defined(WASMER_COMPILER_ENABLED)
void wasm_config_set_compiler(wasm_config_t *config, wasmer_compiler_t compiler);
#endif

void wasm_config_set_engine(wasm_config_t *config, wasmer_engine_t engine);

void wasm_module_name(const wasm_module_t *module, wasm_name_t *out);

bool wasm_module_set_name(wasm_module_t *module, const wasm_name_t *name);

#if defined(WASMER_WASI_ENABLED)
/**
 * Non-standard function to get the module name of a
 * `wasm_named_extern_t`.
 */
const wasm_name_t *wasm_named_extern_module(const wasm_named_extern_t *named_extern);
#endif

#if defined(WASMER_WASI_ENABLED)
/**
 * Non-standard function to get the name of a `wasm_named_extern_t`.
 */
const wasm_name_t *wasm_named_extern_name(const wasm_named_extern_t *named_extern);
#endif

#if defined(WASMER_WASI_ENABLED)
/**
 * Non-standard function to get the wrapped extern of a
 * `wasm_named_extern_t`.
 */
const wasm_extern_t *wasm_named_extern_unwrap(const wasm_named_extern_t *named_extern);
#endif

#if defined(WASMER_WASI_ENABLED)
/**
 *Performs a deep copy of a vector of [`wasm_named_extern_t`].
 */
void wasm_named_extern_vec_copy(wasm_named_extern_vec_t *out_ptr,
                                const wasm_named_extern_vec_t *in_ptr);
#endif

#if defined(WASMER_WASI_ENABLED)
/**
 *Deletes a vector of [`wasm_named_extern_t`].
 *
 *# Example
 *
 *See the [`wasm_named_extern_vec_t`] type to get an example.
 */
void wasm_named_extern_vec_delete(wasm_named_extern_vec_t *ptr);
#endif

#if defined(WASMER_WASI_ENABLED)
/**
 *Creates a new vector of [`wasm_named_extern_t`].
 */
void wasm_named_extern_vec_new(wasm_named_extern_vec_t *out,
                               uintptr_t length,
                               wasm_named_extern_t *const *init);
#endif

#if defined(WASMER_WASI_ENABLED)
/**
 *Creates an empty vector of [`wasm_named_extern_t`].
 *
 *# Example
 *
 *```rust # use inline_c::assert_c; # fn main() { #    (assert_c! { # #include "tests/wasmer_wasm.h" # int main() {     // Creates an empty vector of `wasm_named_extern_t`.     wasm_named_extern_vec_t vector;     wasm_named_extern_vec_new_empty(&vector);
 *
 *    // Check that it is empty.     assert(vector.size == 0);
 *
 *    // Free it.     wasm_named_extern_vec_delete(&vector); } #    }) #    .success(); # } ```
 */
void wasm_named_extern_vec_new_empty(wasm_named_extern_vec_t *out);
#endif

#if defined(WASMER_WASI_ENABLED)
/**
 *Creates a new uninitialized vector of [`wasm_named_extern_t`].
 *
 *# Example
 *
 *```rust # use inline_c::assert_c; # fn main() { #    (assert_c! { # #include "tests/wasmer_wasm.h" # int main() {     // Creates an empty vector of `wasm_named_extern_t`.     wasm_named_extern_vec_t vector;     wasm_named_extern_vec_new_uninitialized(&vector, 3);
 *
 *    // Check that it contains 3 items.     assert(vector.size == 3);
 *
 *    // Free it.     wasm_named_extern_vec_delete(&vector); } #    }) #    .success(); # } ```
 */
void wasm_named_extern_vec_new_uninitialized(wasm_named_extern_vec_t *out,
                                             uintptr_t length);
#endif

/**
 * Gets the length in bytes of the last error if any, zero otherwise.
 *
 * This can be used to dynamically allocate a buffer with the correct number of
 * bytes needed to store a message.
 *
 * # Example
 *
 * See this module's documentation to get a complete example.
 */
int wasmer_last_error_length(void);

int wasmer_last_error_message(char *buffer, int length);

const char *wasmer_version(void);

uint8_t wasmer_version_major(void);

uint8_t wasmer_version_minor(void);

uint8_t wasmer_version_patch(void);

const char *wasmer_version_pre(void);

void wat2wasm(const wasm_byte_vec_t *wat, wasm_byte_vec_t *out);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* WASMER_WASM_H */
