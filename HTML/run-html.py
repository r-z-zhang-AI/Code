from selenium import webdriver
import time
import os

def open_chrome_with_multiple_html(files):
    # Ensure all files exist
    for file_path in files:
        if not os.path.exists(file_path):
            print(f"File {file_path} does not exist.")
            return

    # Create a list to store WebDriver instances
    drivers = []

    try:
        # Open each file in a separate browser window
        for file_path in files:
            driver = webdriver.Chrome()  # Create a new WebDriver instance
            driver.get(f'file://{os.path.abspath(file_path)}')  # Open the local HTML file
            drivers.append(driver)  # Add the instance to the list

        # Keep the browser windows open for a while to view the content
        time.sleep(120)  # Adjust the time as needed
    finally:
        # Close all browser windows
        for driver in drivers:
            driver.quit()

# List of HTML file paths
html_file_paths = [
    '/home/ruizhe/Github/Code/HTML/firework/firework.html',
]

# Open multiple HTML files
open_chrome_with_multiple_html(html_file_paths)
