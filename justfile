# Build the project (default recipe)
build:
    if ! test -d build; then \
        conan install . --output-folder=build --build=missing --profile:all=profiles/detect; \
        cmake -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake \
            -DCMAKE_BUILD_TYPE=Release; \
    fi

    cmake --build build

# Build and run the main executable
run: build
    ./build/sandbox

# Build and run tests
test: build
    ctest --test-dir build --output-on-failure

# Lint with Clang-Tidy
lint: build
    clang-tidy -p build --quiet --use-color --warnings-as-errors='*' \
        $(jq -r '.[].file' build/compile_commands.json | sort -u)

# Check formatting with Clang-Format
fmt-check:
    git ls-files -z '*.cpp' '*.hpp' | xargs -0 clang-format --dry-run --Werror \
        && echo 'Formatting check passed'

# Check spelling with Codebook
spell-check:
    git ls-files -z | xargs -0 codebook-lsp lint

# Full clean rebuild
rebuild: clean build

# Remove build artifacts
clean:
    rm -rf build
