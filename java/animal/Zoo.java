package it.unipr.animal;

import java.util.Arrays;

public class Zoo {
	
	private Animali[] zoo;
	private int l;
	
	public Zoo() {
		this(null,0);
	}
	public Zoo(Animali[] zoo, int l) {
		if (zoo == null) {
			zoo = new Animali[0];
			this.l = 0;
		}else {	
			this.zoo = zoo; // copio riferimento perchè voglio modificare anche l'array
			 this.l = l;
		}
	}
	public void add(Animali other) {
		
		Animali[] nuovoZoo = new Animali[zoo.length + 1];
		
		for (int i = 0; i < zoo.length; i++) {
			nuovoZoo[i] = zoo[i];
		}
		
		nuovoZoo[zoo.length] = other;
		l++;
		this.zoo = nuovoZoo;
	}
	
	public int size() {
		return l;
	}
	
	public String toString() {
		return Arrays.toString(zoo) + "\nlunghezza: " + l;
	}
}
