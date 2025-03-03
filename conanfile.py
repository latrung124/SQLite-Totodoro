from conan import ConanFile

class SqliteRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("sqlitecpp/3.3.2")

    def build_requirements(self):
        self.build_requires("cmake/3.22.6")
