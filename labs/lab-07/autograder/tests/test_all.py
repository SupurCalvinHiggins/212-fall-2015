from autograder_base import AutograderBase


class TestAll(AutograderBase):
	def test_playlist_period(self) -> None:
		requirements = ['playlist_period.cpp']
		dependencies = ['playlist_period.h', 'test_playlist_period.cpp', 'doctest.h']
		executable_name = 'test_playlist_period'
		cpp_files = ['playlist_period.cpp', 'test_playlist_period.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_playlist_period_analysis(self) -> None:
		analysis = 'playlist_period.md'
		self.test_playlist_period()
		self.assert_analysis_tests(analysis)

	def test_bug_bisect(self) -> None:
		requirements = ['bug_bisect.cpp']
		dependencies = ['bug_bisect.h', 'test_bug_bisect.cpp', 'doctest.h']
		executable_name = 'test_bug_bisect'
		cpp_files = ['bug_bisect.cpp', 'test_bug_bisect.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_bug_bisect_analysis(self) -> None:
		analysis = 'bug_bisect.md'
		self.test_bug_bisect()
		self.assert_analysis_tests(analysis)

	def test_perfect_plunder(self) -> None:
		requirements = ['perfect_plunder.cpp']
		dependencies = ['perfect_plunder.h', 'test_perfect_plunder.cpp', 'doctest.h']
		executable_name = 'test_perfect_plunder'
		cpp_files = ['perfect_plunder.cpp', 'test_perfect_plunder.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_perfect_plunder_analysis(self) -> None:
		analysis = 'perfect_plunder.md'
		self.test_perfect_plunder()
		self.assert_analysis_tests(analysis)

	def test_genetic_gap(self) -> None:
		requirements = ['genetic_gap.cpp']
		dependencies = ['genetic_gap.h', 'test_genetic_gap.cpp', 'doctest.h']
		executable_name = 'test_genetic_gap'
		cpp_files = ['genetic_gap.cpp', 'test_genetic_gap.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_genetic_gap_analysis(self) -> None:
		analysis = 'genetic_gap.md'
		self.test_genetic_gap()
		self.assert_analysis_tests(analysis)

	def test_roaming_roomba(self) -> None:
		requirements = ['roaming_roomba.cpp']
		dependencies = ['roaming_roomba.h', 'test_roaming_roomba.cpp', 'doctest.h']
		executable_name = 'test_roaming_roomba'
		cpp_files = ['roaming_roomba.cpp', 'test_roaming_roomba.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_roaming_roomba_analysis(self) -> None:
		analysis = 'roaming_roomba.md'
		self.test_roaming_roomba()
		self.assert_analysis_tests(analysis)

	def test_strategic_silicon(self) -> None:
		requirements = ['strategic_silicon.cpp']
		dependencies = ['strategic_silicon.h', 'test_strategic_silicon.cpp', 'doctest.h']
		executable_name = 'test_strategic_silicon'
		cpp_files = ['strategic_silicon.cpp', 'test_strategic_silicon.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_strategic_silicon_analysis(self) -> None:
		analysis = 'strategic_silicon.md'
		self.test_strategic_silicon()
		self.assert_analysis_tests(analysis)
