import pytest
from typing import Callable
from build import algorithms


@pytest.fixture
def algorithmf1():
    return algorithms.AlgorithmF1()


@pytest.fixture
def algorithmf2():
    return algorithms.AlgorithmF2()


@pytest.fixture
def algorithmf3():
    return algorithms.AlgorithmF3()


@pytest.fixture
def algorithmd1():
    return algorithms.AlgorithmD1()


@pytest.fixture
def algorithmd2():
    return algorithms.AlgorithmD2()


@pytest.fixture
def algorithmd3():
    return algorithms.AlgorithmD3()


class TestSearch:

    ENVIRONMENT_1_DEFAULTS = {
        "num_nodes": 6,
        "node_values": [],
        "node_names": [],
        "edges": [(0, 1), (0, 2), (1, 4), (2, 3), (2, 4), (3, 4), (3, 5), (4, 5)],
        "start_node_idx": 0,
        "goal_node_idx": 5
    }

    ENVIRONMENT_1V_DEFAULTS = {
        "num_nodes": 6,
        "node_values": [[0.0], [1.0], [1.0], [2.0], [9.0], [6.0]],
        "node_names": [],
        "edges": [(0, 1), (0, 2), (1, 4), (2, 3), (2, 4), (3, 4), (3, 5), (4, 5)],
        "start_node_idx": 0,
        "goal_node_idx": 5
    }

    ENVIRONMENT_2_DEFAULTS = {
        "num_nodes": 6,
        "node_values": [(0.0, 0.0), (1.0, 0.0), (1.0, 0.0), (2.0, 0.0), (9.0, 0.0), (6.0, 0.0)],
        "node_names": [],
        "edges": [(0, 1), (0, 2), (1, 4), (2, 3), (2, 4), (3, 4), (3, 5), (4, 5)],
        "start_node_idx": 0,
        "goal_node_idx": 5
    }

    ENVIRONMENT_3_DEFAULTS = {
        "num_nodes": 6,
        "node_values": [(0.0, 0.0, 0.0), (1.0, 0.0, 0.0), (1.0, 0.0, 0.0), (2.0, 0.0, 0.0), (9.0, 0.0, 0.0), (6.0, 0.0, 0.0)],
        "node_names": [],
        "edges": [(0, 1), (0, 2), (1, 4), (2, 3), (2, 4), (3, 4), (3, 5), (4, 5)],
        "start_node_idx": 0,
        "goal_node_idx": 5
    }

    def test_algorithmsd1_default(self, algorithmd1: Callable):
        result = algorithmd1.search(**self.ENVIRONMENT_1_DEFAULTS)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithmsd1_bfs_type_1(self, algorithmd1: Callable):
        result = algorithmd1.search(
            **self.ENVIRONMENT_1_DEFAULTS, method=algorithms.SearchAlgorithm.BREADTH_FIRST_SEARCH)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithmsd1_bfs_type_2(self, algorithmd1: Callable):
        result = algorithmd1.search(**self.ENVIRONMENT_1_DEFAULTS, method=algorithms.SearchAlgorithm.BREADTH_FIRST_SEARCH,
                                    distance_metric=algorithms.DistanceMetric.MANHATTAN, node_prefix_name="", use_node_value=True, bidirectional=True)
        assert [i[0].getName() for i in result] == ["0", "1", "4", "5"]

    def test_algorithmsd1_dfs_type_1(self, algorithmd1: Callable):
        result = algorithmd1.search(**self.ENVIRONMENT_1_DEFAULTS, method=algorithms.SearchAlgorithm.DEPTH_FIRST_SEARCH,
                                    distance_metric=algorithms.DistanceMetric.MANHATTAN)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_2", "Node_4", "Node_5"]

    def test_algorithmsd1_ucs_type_1(self, algorithmd1: Callable):
        result = algorithmd1.search(**self.ENVIRONMENT_1_DEFAULTS, method=algorithms.SearchAlgorithm.UNIFORM_COST_SEARCH,
                                    distance_metric=algorithms.DistanceMetric.MANHATTAN)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithmsd1_ucs_type_2(self, algorithmd1: Callable):
        result = algorithmd1.search(**self.ENVIRONMENT_1V_DEFAULTS, method=algorithms.SearchAlgorithm.UNIFORM_COST_SEARCH,
                                    distance_metric=algorithms.DistanceMetric.MANHATTAN)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_2", "Node_3", "Node_5"]

    def test_algorithmsf1(self, algorithmf1: Callable):
        result = algorithmf1.search(**self.ENVIRONMENT_1_DEFAULTS)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithmsf2(self, algorithmf2: Callable):
        result = algorithmf2.search(**self.ENVIRONMENT_2_DEFAULTS)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithmsf3(self, algorithmf3: Callable):
        result = algorithmf3.search(**self.ENVIRONMENT_3_DEFAULTS)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithmsd1(self, algorithmd1: Callable):
        result = algorithmd1.search(**self.ENVIRONMENT_1_DEFAULTS)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithmsd2(self, algorithmd2: Callable):
        result = algorithmd2.search(**self.ENVIRONMENT_2_DEFAULTS)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithmsd3(self, algorithmd3: Callable):
        result = algorithmd3.search(**self.ENVIRONMENT_3_DEFAULTS)
        assert [i[0].getName() for i in result] == [
            "Node_0", "Node_1", "Node_4", "Node_5"]

    def test_algorithms_dim_mismatch(self, algorithmd1: Callable):
        with pytest.raises(TypeError):
            algorithmd1.search(**self.ENVIRONMENT_2_DEFAULTS)
