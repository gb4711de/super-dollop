"""Tests for weight conversions"""
import pytest
from unit_converter.weight import (
    kg_to_lbs, lbs_to_kg,
    kg_to_oz, oz_to_kg
)


def test_kg_to_lbs():
    """Test kilograms to pounds conversion"""
    assert abs(kg_to_lbs(1) - 2.20462) < 0.0001
    assert abs(kg_to_lbs(10) - 22.0462) < 0.001


def test_lbs_to_kg():
    """Test pounds to kilograms conversion"""
    assert abs(lbs_to_kg(1) - 0.453592) < 0.0001
    assert abs(lbs_to_kg(10) - 4.53592) < 0.001


def test_kg_to_oz():
    """Test kilograms to ounces conversion"""
    assert abs(kg_to_oz(1) - 35.274) < 0.001
    assert abs(kg_to_oz(2) - 70.548) < 0.001


def test_oz_to_kg():
    """Test ounces to kilograms conversion"""
    assert abs(oz_to_kg(1) - 0.0283495) < 0.00001
    assert abs(oz_to_kg(35.274) - 1) < 0.001
