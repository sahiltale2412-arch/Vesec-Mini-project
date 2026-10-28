# Student Expense Tracker
 
expenses = []
 
def add_expense():
    try:
        amount = float(input("Enter expense amount (Rs.): "))
 
        if amount <= 0:
            print("Amount must be greater than zero.")
            return
 
        category = input("Enter category (Food/Travel/Books/Other): ").strip()
        description = input("Enter description: ").strip()
 
        expense = {
            "amount": amount,
            "category": category if category else "Other",
            "description": description if description else "No description"
        }
 
        expenses.append(expense)
        print("Expense added successfully!")
 
    except ValueError:
        print("Please enter a valid amount.")
 
 
def view_expenses():
    if not expenses:
        print("No expenses recorded yet.")
        return
 
    print("\n--- All Expenses ---")
 
    for i, expense in enumerate(expenses, start=1):
        print(
            f"{i}. Rs. {expense['amount']:.2f} | "
            f"{expense['category']} | "
            f"{expense['description']}"
        )
 
 
def show_total():
    total = sum(expense["amount"] for expense in expenses)
    print(f"Total expenses: Rs. {total:.2f}")
 
 
def search_category():
    category = input("Enter category to search: ").strip().lower()
 
    found = [
        expense for expense in expenses
        if expense["category"].lower() == category
    ]
 
    if not found:
        print("No expenses found in this category.")
        return
 
    print("\n--- Search Results ---")
 
    for expense in found:
        print(
            f"Rs. {expense['amount']:.2f} | "
            f"{expense['category']} | "
            f"{expense['description']}"
        )
 
 
def delete_expense():
    view_expenses()
 
    if not expenses:
        return
 
    try:
        number = int(input("Enter expense number to delete: "))
 
        if 1 <= number <= len(expenses):
            removed = expenses.pop(number - 1)
            print("Expense deleted successfully!")
        else:
            print("Invalid expense number.")
 
    except ValueError:
        print("Please enter a valid number.")
 
 
def main():
    while True:
        print("\n===== Student Expense Tracker =====")
        print("1. Add Expense")
        print("2. View All Expenses")
        print("3. Show Total Expenses")
        print("4. Search by Category")
        print("5. Delete Expense")
        print("6. Exit")
 
        choice = input("Enter your choice (1-6): ")
 
        if choice == "1":
            add_expense()
        elif choice == "2":
            view_expenses()
        elif choice == "3":
            show_total()
        elif choice == "4":
            search_category()
        elif choice == "5":
            delete_expense()
        elif choice == "6":
            print("Thank you for using Student Expense Tracker!")
            break
        else:
            print("Invalid choice. Please try again.")
 
 
if __name__ == "__main__":
    main()

