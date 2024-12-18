import numpy as np
import sympy as sp

# Define variables
x = sp.symbols('x')
y = sp.sqrt(x)  # Positive branch of the parabola

# Point A
ax, ay = -1/2, 1/4

# (1) Calculate slope of AP
def ap_slope(x_val):
    y_val = sp.sqrt(x_val)
    return (y_val - ay) / (x_val - ax)

# (2) Circle centered at midpoint of AB with radius as half the length of AB
bx, by = 3/2, 9/4
cx, cy = (ax + bx) / 2, (ay + by) / 2
r_squared = ((bx - ax) / 2)**2 + ((by - ay) / 2)**2

def ap_pq_product(x_val):
    y_val = np.sqrt(x_val)  # y on parabola
    ap_length = np.sqrt((x_val - ax)**2 + (y_val - ay)**2)
    
    # Solve intersection of line AP with circle
    dx, dy = x_val - ax, y_val - ay
    a = dx**2 + dy**2
    b = 2 * (dx * (ax - cx) + dy * (ay - cy))
    c = (ax - cx)**2 + (ay - cy)**2 - r_squared
    discriminant = b**2 - 4 * a * c

    if discriminant < 0:
        return -1  # No intersection

    t = (-b + np.sqrt(discriminant)) / (2 * a)
    qx, qy = ax + t * dx, ay + t * dy
    pq_length = np.sqrt((qx - x_val)**2 + (qy - y_val)**2)

    return ap_length * pq_length

# Find the range of slopes and the maximum product
x_vals = np.linspace(-0.49, 1.49, 1000)
slopes = [ap_slope(val) for val in x_vals]
products = [ap_pq_product(val) for val in x_vals]

print(f"Slope range: [{min(slopes):.4f}, {max(slopes):.4f}]")
print(f"Max |AP| * |PQ|: {max(products):.4f}")
