import operator

def evaluate_postfix(expression):
    """
    Evaluates a postfix expression (Reverse Polish Notation) using a stack.

    The expression must be a string with tokens (operands and operators) 
    separated by spaces (e.g., "10 5 + 3 *").
    
    Args:
        expression (str): The space-separated postfix expression.

    Returns:
        float/int: The result of the evaluation.
        
    Raises:
        ValueError: If the expression is invalid (too many operators/operands).
    """
    
    # Dictionary to map operators to their respective functions
    # This makes the code cleaner than a chain of if/elif statements.
    ops = {
        '+': operator.add,
        '-': operator.sub,
        '*': operator.mul,
        '/': operator.truediv, # Use truediv for standard division (returns float)
        '^': operator.pow
    }

    # Initialize the stack
    stack = []
    
    # Split the expression string into a list of tokens
    tokens = expression.split()

    print(f"Tokens to process: {tokens}")
    print("-" * 30)

    # Iterate through each token in the expression
    for token in tokens:
        if token.isdigit() or (token.startswith('-') and token[1:].isdigit()):
            # 1. If the token is an operand (a number), push it onto the stack.
            # We convert it to a floating-point number to handle division results.
            try:
                stack.append(float(token))
                print(f"Pushed operand: {token} | Stack: {stack}")
            except ValueError:
                # This should ideally not happen with isdigit check, but for robustness
                raise ValueError(f"Invalid operand: {token}")

        elif token in ops:
            # 2. If the token is an operator, perform the operation.
            try:
                # Pop the top two operands (Note: order is important for non-commutative ops like - and /)
                operand2 = stack.pop()
                operand1 = stack.pop()
                
                # Perform the operation
                result = ops[token](operand1, operand2)
                
                # Push the result back onto the stack
                stack.append(result)
                print(f"Calculated: {operand1} {token} {operand2} = {result} | Stack: {stack}")
                
            except IndexError:
                # Catches error if stack doesn't have 2 operands (invalid expression)
                raise ValueError("Invalid expression: Insufficient operands for operator " + token)
            except ZeroDivisionError:
                raise ValueError("Cannot divide by zero.")
        
        else:
            # Catches tokens that are neither a valid number nor a recognized operator
            raise ValueError(f"Invalid token encountered: {token}")
            
    print("-" * 30)
    
    # 3. The final result should be the only item left in the stack
    if len(stack) == 1:
        # Return as integer if the result is a whole number
        final_result = stack[0]
        if final_result == int(final_result):
            return int(final_result)
        return final_result
    else:
        # Catches error if stack has too many items left (invalid expression)
        raise ValueError("Invalid expression: Too many operands or insufficient operators.")

# --- Example Usage ---

# Example 1: Simple addition
expression1 = "10 5 +" # Equivalent to (10 + 5)
print(f"Expression: '{expression1}'")
try:
    print(f"Result: {evaluate_postfix(expression1)}\n")
except ValueError as e:
    print(f"Error: {e}\n")


# Example 2: Complex expression
expression2 = "2 3 1 * + 9 -" # Equivalent to ((2 + (3 * 1)) - 9) -> (5 - 9) -> -4
print(f"Expression: '{expression2}'")
try:
    print(f"Result: {evaluate_postfix(expression2)}\n")
except ValueError as e:
    print(f"Error: {e}\n")
    

# Example 3: Division and exponents
expression3 = "12 2 / 3 ^" # Equivalent to ((12 / 2) ^ 3) -> 6^3 -> 216
print(f"Expression: '{expression3}'")
try:
    print(f"Result: {evaluate_postfix(expression3)}\n")
except ValueError as e:
    print(f"Error: {e}\n")
    
    
# Example 4: Invalid expression (too many operands)
expression4 = "5 1 2 +"
print(f"Expression: '{expression4}'")
try:
    print(f"Result: {evaluate_postfix(expression4)}\n")
except ValueError as e:
    print(f"Error: {e}\n")
