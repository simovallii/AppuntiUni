package it.unipr.ep;

import java.util.Objects;

public class Episode {

	private final String title;
	private final String trama;
	private final Episode next;
	
	public Episode(String title, String trama, Episode next) {
		
		Objects.requireNonNull(title, trama);
		this.title = title;
		this.trama = trama;
		this.next = next;
	}
	
	public String toString() {
		
		return "titolo: " + title + "trama: " + trama + "\n" + next;	}
	
	public boolean equals(Episode other) {
		
		return this.title.equalsIgnoreCase(other.title) && this.trama.equalsIgnoreCase(other.trama);
	}
}
