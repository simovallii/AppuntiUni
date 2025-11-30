package it.unipr.ep;

import java.util.Objects;

public class Serial {
	
	private final String title;
	private final Episode inizio;
	
	public Serial(String title, Episode inizio) {
		
		Objects.requireNonNull(title);
		this.title = title;
		this.inizio = inizio;
	}
	
	public String toString() {
		
		return "Titolo serie: " + title + "episodi:" + inizio.toString();
	}
	
	public boolean equals(Serial other) {
		
		return this.title.equalsIgnoreCase(other.title) && inizio.equals(other.inizio);
	}
}
