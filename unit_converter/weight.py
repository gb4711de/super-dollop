"""
Weight conversion functions
"""


def kg_to_lbs(kg):
    """Convert kilograms to pounds"""
    return kg * 2.20462


def lbs_to_kg(lbs):
    """Convert pounds to kilograms"""
    return lbs / 2.20462


def kg_to_oz(kg):
    """Convert kilograms to ounces"""
    return kg * 35.274


def oz_to_kg(oz):
    """Convert ounces to kilograms"""
    return oz / 35.274


# Dictionary of available weight conversions
WEIGHT_CONVERSIONS = {
    'kg_to_lbs': kg_to_lbs,
    'lbs_to_kg': lbs_to_kg,
    'kg_to_oz': kg_to_oz,
    'oz_to_kg': oz_to_kg,
}
