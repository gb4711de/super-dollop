"""
Length conversion functions
"""


def km_to_miles(km):
    """Convert kilometers to miles"""
    return km * 0.621371


def miles_to_km(miles):
    """Convert miles to kilometers"""
    return miles / 0.621371


def meters_to_feet(meters):
    """Convert meters to feet"""
    return meters * 3.28084


def feet_to_meters(feet):
    """Convert feet to meters"""
    return feet / 3.28084


# Dictionary of available length conversions
LENGTH_CONVERSIONS = {
    'km_to_miles': km_to_miles,
    'miles_to_km': miles_to_km,
    'meters_to_feet': meters_to_feet,
    'feet_to_meters': feet_to_meters,
}
