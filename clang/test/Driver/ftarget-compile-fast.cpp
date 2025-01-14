// Test -ftarget-compile-fast behaviors

// RUN: %clang -### -target x86_64-unknown-linux-gnu -fsycl --offload-new-driver \
// RUN:    -fsycl-targets=spir64_gen -ftarget-compile-fast %s 2>&1 \
// RUN:   | FileCheck -check-prefix=TARGET_COMPILE_FAST_GEN %s
// RUN: %clang_cl -### --target=x86_64-pc-windows-msvc -fsycl --offload-new-driver \
// RUN:     -fsycl-targets=spir64_gen -ftarget-compile-fast %s 2>&1 \
// RUN:   | FileCheck -check-prefix=TARGET_COMPILE_FAST_GEN %s

// TARGET_COMPILE_FAST_GEN: clang-offload-packager
// TARGET_COMPILE_FAST_GEN: compile-opts={{.*}}-options -igc_opts 'PartitionUnit=1,SubroutineThreshold=50000'

// RUN: %clang -### -target x86_64-unknown-linux-gnu -fsycl --offload-new-driver \
// RUN:    -ftarget-compile-fast %s 2>&1 \
// RUN:   | FileCheck -check-prefix=TARGET_COMPILE_FAST_JIT %s
// RUN: %clang_cl -### --target=x86_64-pc-windows-msvc -fsycl --offload-new-driver \
// RUN:     -ftarget-compile-fast %s 2>&1 \
// RUN:   | FileCheck -check-prefix=TARGET_COMPILE_FAST_JIT %s

// TARGET_COMPILE_FAST_JIT: clang-offload-packager
// TARGET_COMPILE_FAST_JIT: compile-opts={{.*}}-ftarget-compile-fast
