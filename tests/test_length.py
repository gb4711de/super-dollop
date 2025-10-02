"""Tests for length conversions"""
import pytest
from unit_converter.length import (
    km_to_miles, miles_to_km,
    meters_to_feet, feet_to_meters
)


def test_km_to_miles():
    """Test kilometers to miles conversion"""
    assert abs(km_to_miles(1) - 0.621371) < 0.0001
    assert abs(km_to_miles(10) - 6.21371) < 0.0001


def test_miles_to_km():
    """Test miles to kilometers conversion"""
    assert abs(miles_to_km(1) - 1.60934) < 0.001
    assert abs(miles_to_km(10) - 16.0934) < 0.001


def test_meters_to_feet():
    """Test meters to feet conversion"""
    assert abs(meters_to_feet(1) - 3.28084) < 0.0001
    assert abs(meters_to_feet(10) - 32.8084) < 0.0001


def test_feet_to_meters():
    """Test feet to meters conversion"""
    assert abs(feet_to_meters(1) - 0.3048) < 0.0001
    assert abs(feet_to_meters(10) - 3.048) < 0.001
