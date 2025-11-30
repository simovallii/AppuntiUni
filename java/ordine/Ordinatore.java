package it.unipr.ordine;

public class Ordinatore<T extends Comparable<T>> {
	
	private T elem;
	
	public Ordinatore(T elem) {
		this.elem = elem;
	}
	
	public int check(T other) {
		
		int cmp = other.compareTo(elem);
		if (cmp < 0) {
			elem = other;
			return 1;
			}
		if (cmp > 0) {
			elem = other;
			return -1;
		}
		elem = other;
		return cmp;
	}
}
