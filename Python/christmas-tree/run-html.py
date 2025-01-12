from selenium import webdriver
import time
import os

def open_chrome_with_html(file_path):
    # Ensure the file exists
    if not os.path.exists(file_path):
        print(f"File {file_path} does not exist.")
        return

    # Set up the Chrome WebDriver (specify path to ChromeDriver if needed)
    # Example: webdriver.Chrome(executable_path='/path/to/chromedriver')
    driver = webdriver.Chrome()

    # Open the local HTML file in Google Chrome
    driver.get(f'file://{os.path.abspath(file_path)}')

    # Keep the browser open for a few seconds to view the content
    time.sleep(30)  # You can adjust the time as needed

    # Optionally, close the browser after some time
    driver.quit()

# Set the path to your HTML file
html_file_path = '/home/ruizhe/Github/Code/Python/christmas-tree/tree.html' 

# Open the HTML file in Google Chrome
open_chrome_with_html(html_file_path)
