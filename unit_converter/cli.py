"""
Main CLI interface for the unit converter tool
"""
import click
from unit_converter.length import LENGTH_CONVERSIONS
from unit_converter.temperature import TEMPERATURE_CONVERSIONS
from unit_converter.weight import WEIGHT_CONVERSIONS


# Combine all conversion dictionaries
ALL_CONVERSIONS = {
    **LENGTH_CONVERSIONS,
    **TEMPERATURE_CONVERSIONS,
    **WEIGHT_CONVERSIONS,
}


@click.group()
@click.version_option(version='0.1.0')
def main():
    """
    Unit Converter CLI Tool
    
    Convert between different units of measurement including:
    - Length (km, miles, meters, feet)
    - Temperature (Celsius, Fahrenheit, Kelvin)
    - Weight (kg, lbs, oz)
    """
    pass


@main.command()
@click.argument('value', type=float)
@click.argument('from_unit')
@click.argument('to_unit')
def convert(value, from_unit, to_unit):
    """
    Convert VALUE from FROM_UNIT to TO_UNIT
    
    Example: convert 100 km miles
    """
    conversion_key = f"{from_unit}_to_{to_unit}"
    
    if conversion_key not in ALL_CONVERSIONS:
        click.echo(f"Error: Conversion from '{from_unit}' to '{to_unit}' is not supported.")
        click.echo("\nAvailable conversions:")
        for key in sorted(ALL_CONVERSIONS.keys()):
            parts = key.split('_to_')
            click.echo(f"  {parts[0]} -> {parts[1]}")
        return
    
    converter = ALL_CONVERSIONS[conversion_key]
    result = converter(value)
    
    click.echo(f"{value} {from_unit} = {result:.4f} {to_unit}")


@main.command()
def list_conversions():
    """List all available unit conversions"""
    click.echo("Available conversions:\n")
    
    click.echo("Length:")
    for key in sorted(LENGTH_CONVERSIONS.keys()):
        parts = key.split('_to_')
        click.echo(f"  {parts[0]} -> {parts[1]}")
    
    click.echo("\nTemperature:")
    for key in sorted(TEMPERATURE_CONVERSIONS.keys()):
        parts = key.split('_to_')
        click.echo(f"  {parts[0]} -> {parts[1]}")
    
    click.echo("\nWeight:")
    for key in sorted(WEIGHT_CONVERSIONS.keys()):
        parts = key.split('_to_')
        click.echo(f"  {parts[0]} -> {parts[1]}")


if __name__ == '__main__':
    main()
