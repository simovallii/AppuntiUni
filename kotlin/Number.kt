fun FilterNumbers(lista: List<Int>, pred : (Int) -> Boolean) : List<Int> {
    return lista.filter {pred(it) }
}

fun main(){

 val numbers = listOf<Int>(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    println(FilterNumbers(numbers, {n -> n%2 == 0}))
    println(FilterNumbers(numbers, {n -> n%2 == 1}))

}
