class Node:
    def __init__(self, coef, exp):
        self.coef = coef  # Coefficient
        self.exp = exp    # Exponent
        self.next = None  # Pointer to the next node

class Polynomial:
    def __init__(self):
        self.head = None

    # Function to input a polynomial
    def input_polynomial(self):
        n = int(input("Enter the number of terms in the polynomial: "))
        for _ in range(n):
            coef, exp = map(int, input("Enter coefficient and exponent: ").split())
            new_node = Node(coef, exp)
            if not self.head:
                self.head = new_node
            else:
                temp = self.head
                while temp.next:
                    temp = temp.next
                temp.next = new_node

    # Function to display the polynomial
    def display_polynomial(self):
        if not self.head:
            print("Polynomial is empty.")
            return
        temp = self.head
        while temp:
            if temp.exp != 0:
                print(f"{temp.coef}x^{temp.exp}", end=" + " if temp.next else "")
            else:
                print(f"{temp.coef}", end=" + " if temp.next else "")
            temp = temp.next
        print()

    # Function to evaluate the polynomial at a given value of x
    def evaluate(self, x):
        result = 0
        temp = self.head
        while temp:
            result += temp.coef * (x ** temp.exp)
            temp = temp.next
        return result

    # Function to add two polynomials
    def add(self, other):
        p1 = self.head
        p2 = other.head
        result = Polynomial()
        while p1 and p2:
            if p1.exp > p2.exp:
                result.append_term(p1.coef, p1.exp)
                p1 = p1.next
            elif p1.exp < p2.exp:
                result.append_term(p2.coef, p2.exp)
                p2 = p2.next
            else:
                result.append_term(p1.coef + p2.coef, p1.exp)
                p1 = p1.next
                p2 = p2.next
        # If any terms are left in p1 or p2
        while p1:
            result.append_term(p1.coef, p1.exp)
            p1 = p1.next
        while p2:
            result.append_term(p2.coef, p2.exp)
            p2 = p2.next
        return result

    # Helper function to append a term to the polynomial
    def append_term(self, coef, exp):
        new_node = Node(coef, exp)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node

# Main function to test the Polynomial class
def main():
    poly1 = Polynomial()
    poly2 = Polynomial()

    print("Enter first polynomial:")
    poly1.input_polynomial()
    print("First Polynomial: ", end="")
    poly1.display_polynomial()

    print("Enter second polynomial:")
    poly2.input_polynomial()
    print("Second Polynomial: ", end="")
    poly2.display_polynomial()

    # Adding polynomials
    sum_poly = poly1.add(poly2)
    print("Sum of the polynomials: ", end="")
    sum_poly.display_polynomial()

    # Evaluate polynomial at a given value of x
    x = int(input("Enter the value of x to evaluate the first polynomial: "))
    result = poly1.evaluate(x)
    print(f"The value of the first polynomial at x = {x} is: {result}")

if __name__ == "__main__":
    main()
