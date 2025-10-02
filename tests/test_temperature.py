"""Tests for temperature conversions"""
import pytest
from unit_converter.temperature import (
    celsius_to_fahrenheit, fahrenheit_to_celsius,
    celsius_to_kelvin, kelvin_to_celsius
)


def test_celsius_to_fahrenheit():
    """Test Celsius to Fahrenheit conversion"""
    assert celsius_to_fahrenheit(0) == 32
    assert celsius_to_fahrenheit(100) == 212
    assert abs(celsius_to_fahrenheit(37) - 98.6) < 0.1


def test_fahrenheit_to_celsius():
    """Test Fahrenheit to Celsius conversion"""
    assert fahrenheit_to_celsius(32) == 0
    assert fahrenheit_to_celsius(212) == 100
    assert abs(fahrenheit_to_celsius(98.6) - 37) < 0.1


def test_celsius_to_kelvin():
    """Test Celsius to Kelvin conversion"""
    assert celsius_to_kelvin(0) == 273.15
    assert celsius_to_kelvin(-273.15) == 0
    assert celsius_to_kelvin(100) == 373.15


def test_kelvin_to_celsius():
    """Test Kelvin to Celsius conversion"""
    assert kelvin_to_celsius(273.15) == 0
    assert kelvin_to_celsius(0) == -273.15
    assert kelvin_to_celsius(373.15) == 100
