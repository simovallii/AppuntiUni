    data class Item(val name: String, val quantity: Int)
        fun main(){

            val unitPriceCalculator : (Item) -> Double = { item -> when(item.name)
            {
                "t-shirt" ->  15.99 * item.quantity
                "jeans" ->  29.99 * item.quantity
                "sneaker" -> 50.00 * item.quantity
                "backpack" ->  42.00 * item.quantity
                else-> 0.0
            }
            }
        val bag = listOf<Item>(Item("t-shirt", 2), Item("jeans", 2), Item("sneaker", 1), Item("backpack", 1))
        println(calculateTotalPrice(bag, unitPriceCalculator))


    }

    fun calculateTotalPrice(items: List<Item>, unitPriceCalculator: (Item) -> Double): Double {
        return items.map{unitPriceCalculator(it)}.sum()
    }


