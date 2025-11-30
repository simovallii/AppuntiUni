package it.unipr.climate;

import java.util.Vector;

public class ClimateDataProcessor {
	
	private Vector<ClimateData> container;
	
	public ClimateDataProcessor() {
		
		this.container = new Vector<ClimateData>();
	}
	
	public void addObject(ClimateData other) {
		
		this.container.add(other);
	}
	
	public float mediaSeaLevel() {
		if(this.container.isEmpty())
			throw new RuntimeException("container vuoto");
		
		int size = 0;
		float n = 0;
		for(ClimateData a : container) {
			if(a instanceof AugmentedClimateData) {
				n += ((AugmentedClimateData) a).seaLevel();
				size++;
			}
		}
		float media = n/size;
		return media;
	}
}
