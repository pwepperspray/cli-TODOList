import tkinter as tk
from tkinter import filedialog
import os

# Function to update the Listbox with folder contents
def browse_folder():
    folder_path = filedialog.askdirectory()  # Open a folder selection dialog
    if folder_path:
        folder_contents.delete(0, tk.END)  # Clear the Listbox
        for item in os.listdir(folder_path):
            folder_contents.insert(tk.END, item)  # Insert folder contents into Listbox

# Create the main window
root = tk.Tk()
root.title("File Explorer")
root.geometry("500x250")

top = tk.Label(root, text = "cli-TODOList made by pwepperspray/cinnamon_rowll")
top.grid(row = 0, column = 5)
# Create a button to browse for a folder
browse_button = tk.Button(root, text="Browse", command=browse_folder)
browse_button.grid(row = 1, column = 1, pady = 2)

# Create a scrollbar for the Listbox

# Start the Tkinter main loop
root.mainloop()
