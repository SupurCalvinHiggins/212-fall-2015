from autograder_base import AutograderBase


class TestAll(AutograderBase):
	def test_set(self) -> None:
		requirements = ['set.h', 'set.cpp']
		dependencies = ['test_set.cpp']
		executable_name = 'test_set'
		cpp_files = ['set.cpp', 'test_set.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_set_analysis(self) -> None:
		analysis = 'set.md'
		self.test_set()
		self.assert_analysis_tests(analysis)

	def test_map(self) -> None:
		requirements = ['map.h', 'map.cpp']
		dependencies = ['test_map.cpp']
		executable_name = 'test_map'
		cpp_files = ['map.cpp', 'test_map.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_map_analysis(self) -> None:
		analysis = 'map.md'
		self.test_map()
		self.assert_analysis_tests(analysis)

	def test_sequence(self) -> None:
		requirements = ['sequence.h', 'sequence.cpp']
		dependencies = ['test_sequence.cpp']
		executable_name = 'test_sequence'
		cpp_files = ['sequence.cpp', 'test_sequence.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_sequence_analysis(self) -> None:
		analysis = 'sequence.md'
		self.test_sequence()
		self.assert_analysis_tests(analysis)
