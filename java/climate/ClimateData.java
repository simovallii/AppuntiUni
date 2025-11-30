package it.unipr.climate;

import java.util.Objects;

public class ClimateData {
	
	protected final String regione;
	protected final double temp;
	protected final double emissione;
	
	public ClimateData(String regione, double temp, double emissione) {
		
		this.regione = regione;
		if(temp <= 10.0 || temp >= 20.0)
			throw new IllegalArgumentException("valore non plausibile");
		this.temp = temp;
		
		if(emissione < 0.0 || emissione > 10.0)
			throw new IllegalArgumentException("valore non plausibile");
		this.emissione = emissione;
	}
	
	public String getRegione() {
		return regione;
	}
	public double getTemp() {
		return temp;
	}
	public double getEmissione() {
		return emissione;
	}
	
	public String toString() {
		return "nome: " + regione + ", Temperatura media: " + temp + ", emissione annua:" + emissione;
	}
	
	public boolean equals(Object obj) {
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(!(this.getClass() == obj.getClass()))
				return false;
		
		ClimateData other = (ClimateData) obj;
		return this.regione.equals(other.regione) && this.temp == other.temp && this.emissione == other.emissione;
	}
	
	public int hashCode() {
		return Objects.hash(regione, temp, emissione);
	}
}
