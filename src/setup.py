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

# Create a button to browse for a folder
browse_button = tk.Button(root, text="Browse Folder", command=browse_folder)
browse_button.pack(pady=10)

# Create a Listbox to display folder contents
folder_contents = tk.Listbox(root, selectmode=tk.SINGLE)
folder_contents.pack(fill=tk.BOTH, expand=True)

# Create a scrollbar for the Listbox
scrollbar = tk.Scrollbar(folder_contents, orient=tk.VERTICAL)
scrollbar.config(command=folder_contents.yview)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
folder_contents.config(yscrollcommand=scrollbar.set)

# Start the Tkinter main loop
root.mainloop()
