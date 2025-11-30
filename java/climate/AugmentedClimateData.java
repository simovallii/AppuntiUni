package it.unipr.climate;

import java.util.Objects;

public class AugmentedClimateData extends ClimateData implements SeaLevel {

	private final float level;
	
	public AugmentedClimateData(String regione, double temp, double emissione, float level) {
		super(regione, temp, emissione);
		this.level = level;
	}
	public float seaLevel() {
		return level;
	}
	
	public String toString() {
		return super.toString() + ", livello del  mare: " + this.level;
	}
	
	public boolean equals(Object obj) {
		super.equals(obj);
		if (this.getClass() != obj.getClass())
			return false;
		
		AugmentedClimateData other = (AugmentedClimateData) obj;
		return this.level == other.level;
	}
	
	public int hashCode() {
		return Objects.hash(super.hashCode(), level);
	}
}
