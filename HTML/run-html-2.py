from selenium import webdriver
import time
import os

def open_chrome_with_multiple_tabs(files):
    # Ensure all files exist
    for file_path in files:
        if not os.path.exists(file_path):
            print(f"File {file_path} does not exist.")
            return

    # Create a single WebDriver instance
    driver = webdriver.Chrome()

    try:
        # Open the first file in the initial tab
        driver.get(f'file://{os.path.abspath(files[0])}')

        # Open remaining files in new tabs
        for file_path in files[1:]:
            driver.execute_script(f"window.open('file://{os.path.abspath(file_path)}', '_blank');")

        # Keep the browser open for a while to view the content
        time.sleep(300)  # Adjust the time as needed
    finally:
        # Close the browser
        driver.quit()

# List of HTML file paths
html_file_paths = [
    '/home/ruizhe/Github/Code/HTML/city.html',
    '/home/ruizhe/Github/Code/HTML/bubble.html',
    '/home/ruizhe/Github/Code/HTML/forest.html',
    '/home/ruizhe/Github/Code/HTML/sky.html',
    '/home/ruizhe/Github/Code/HTML/starry-sky.html'
]

# Open multiple HTML files as tabs in a single browser window
open_chrome_with_multiple_tabs(html_file_paths)
