import tkinter as tk
import random

def draw_christmas_tree(canvas, height):
    """
    Draw a graphical representation of a Christmas tree using Tkinter.

    Parameters:
        canvas (tk.Canvas): The canvas on which to draw the tree.
        height (int): The height of the tree (number of levels).

    Returns:
        None
    """
    canvas_width = int(canvas['width'])
    canvas_height = int(canvas['height'])
    tree_width = canvas_width // 2
    tree_height = canvas_height - 100  # Reserve space for the trunk

    # Draw tree body
    level_height = tree_height // height
    for i in range(height):
        x0 = canvas_width // 2 - (i + 1) * tree_width // (2 * height)
        x1 = canvas_width // 2 + (i + 1) * tree_width // (2 * height)
        
        # Adjust y0 and y1 to create the "nesting" effect
        y0 = 50 + i * level_height - (i * 5)  # Slightly shift each triangle downwards
        y1 = 50 + (i + 1) * level_height - (i * 5)  # Shift the bottom of the triangle similarly

        canvas.create_polygon(x0, y1, x1, y1, canvas_width // 2, y0, fill='green', outline='black')

        # Increase the number of decorations on each level, especially for bottom layers
        num_decorations = random.randint(3, 7) if i < height - 1 else random.randint(25, 30)  # More decorations at bottom levels
        for _ in range(num_decorations):
            decoration_x = random.randint(x0, x1)
            decoration_y = random.randint(y0, y1)
            decoration_color = random.choice(['red', 'gold', 'blue', 'silver', 'pink', 'purple', 'orange'])
            decoration_shape = random.choice(['oval', 'star', 'square', 'heart', 'diamond', 'circle', 'ball'])

            if decoration_shape == 'oval':
                canvas.create_oval(
                    decoration_x - 5, decoration_y - 5,
                    decoration_x + 5, decoration_y + 5,
                    fill=decoration_color, outline=decoration_color
                )
            elif decoration_shape == 'square':
                canvas.create_rectangle(
                    decoration_x - 5, decoration_y - 5,
                    decoration_x + 5, decoration_y + 5,
                    fill=decoration_color, outline=decoration_color
                )
            elif decoration_shape == 'star':
                size = 6
                points = [
                    decoration_x, decoration_y - size,  # Top
                    decoration_x + size // 2, decoration_y + size // 3,  # Bottom right
                    decoration_x - size // 2, decoration_y + size // 3,  # Bottom left
                    decoration_x + size, decoration_y - size // 2,  # Right
                    decoration_x - size, decoration_y - size // 2  # Left
                ]
                canvas.create_polygon(points, fill=decoration_color, outline=decoration_color)
            elif decoration_shape == 'heart':
                canvas.create_polygon(
                    decoration_x, decoration_y - 6,
                    decoration_x + 6, decoration_y,
                    decoration_x, decoration_y + 6,
                    decoration_x - 6, decoration_y,
                    fill=decoration_color, outline=decoration_color
                )
            elif decoration_shape == 'diamond':
                canvas.create_polygon(
                    decoration_x, decoration_y - 6,
                    decoration_x + 6, decoration_y,
                    decoration_x, decoration_y + 6,
                    decoration_x - 6, decoration_y,
                    fill=decoration_color, outline=decoration_color
                )
            elif decoration_shape == 'circle':
                canvas.create_oval(
                    decoration_x - 5, decoration_y - 5,
                    decoration_x + 5, decoration_y + 5,
                    fill=decoration_color, outline=decoration_color
                )
            elif decoration_shape == 'ball':
                canvas.create_oval(
                    decoration_x - 8, decoration_y - 8,
                    decoration_x + 8, decoration_y + 8,
                    fill=decoration_color, outline=decoration_color
                )

    # For the bottom triangle, y1 will be the bottom edge (the bottom-most point)
    last_triangle_y0 = 50 + (height - 1) * level_height - ((height - 1) * 5)  # Bottom edge of the last triangle
    last_triangle_y1 = 50 + height * level_height - ((height - 1) * 5)  # Bottom edge of the last triangle

    # Calculate the position of the tree trunk to align with the bottom triangle
    trunk_width = tree_width // 7
    trunk_height = 70  # Fixed height for trunk
    x0 = canvas_width // 2 - trunk_width // 2
    x1 = canvas_width // 2 + trunk_width // 2

    # Set y0 as the position for the top of the trunk to align with the bottom of the last triangle
    y0 = last_triangle_y1
    y1 = y0 + trunk_height

    # Draw the trunk
    canvas.create_rectangle(x0, y0, x1, y1, fill='brown', outline='black')

    # Add a gold star at the top of the tree
    star_size = 50  # Increase size
    star_x = canvas_width // 2
    star_y = 50  # Tree starts from y=50, so this will place it near the top

    # Use Unicode character for the star (★)
    canvas.create_text(star_x, star_y, text="★", font=("Arial", star_size), fill="gold")

def main():
    """Create a Tkinter window and draw a Christmas tree."""
    root = tk.Tk()
    root.title("Christmas Tree")

    canvas_width = 400
    canvas_height = 600
    canvas = tk.Canvas(root, width=canvas_width, height=canvas_height, bg='white')
    canvas.pack()

    height = 10  # Adjust the height of the tree here
    draw_christmas_tree(canvas, height)

    root.mainloop()

if __name__ == "__main__":
    main()
