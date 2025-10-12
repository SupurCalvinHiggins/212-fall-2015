from autograder_base import AutograderBase


class TestAll(AutograderBase):
	def test_pseudoset(self) -> None:
		requirements = ['pseudoset.h', 'pseudoset.cpp']
		dependencies = ['test_pseudoset.cpp', 'doctest.h']
		executable_name = 'test_pseudoset'
		cpp_files = ['pseudoset.cpp', 'test_pseudoset.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_pseudoset_analysis(self) -> None:
		analysis = 'pseudoset.md'
		self.test_pseudoset()
		self.assert_analysis_tests(analysis)

	def test_set(self) -> None:
		requirements = ['set.h', 'set.cpp']
		dependencies = ['test_set.cpp', 'doctest.h']
		executable_name = 'test_set'
		cpp_files = ['set.cpp', 'test_set.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_set_analysis(self) -> None:
		analysis = 'set.md'
		self.test_set()
		self.assert_analysis_tests(analysis)
