
public class Temperature {
	
	public static final char CELSIUS = 'C';
	public static final char FAHRENHEIT = 'F';

	private double temperature;
	private char scale;
	
	public Temperature( double temp, char scale ) {
		temperature = temp;
		
		this.scale = Character.toUpperCase(scale);
		if ( this.scale != FAHRENHEIT && this.scale != CELSIUS ) {
			this.scale = CELSIUS;
		}
	}
	
	public double asFahrenheit() {
		double rtn = temperature;
		if ( scale != FAHRENHEIT ) {
			rtn = (9.0/5) * temperature + 32;
		}
		return rtn;
	}
	
	public double asCelsius() {
		double rtn = temperature;
		if ( scale != CELSIUS ) {
			rtn = (5.0/9) * (temperature - 32.0);
		}
		return rtn;
	}
	
	public double getTemperature() {
		return temperature;
	}
	
	public char getScale() {
		return scale;
	}
	
	public String toString() {
		return String.format("Temperature = %.1f %c", 
							 getTemperature(), getScale() );
	}
	
}
