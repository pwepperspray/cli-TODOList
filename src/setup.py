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
    print(folder_path)
    
# Create the main window
root = tk.Tk()
root.title("cli-TODOList")
root.geometry("500x250")

toptext = tk.Label(root, text = "cli-TODOList made by pwepperspray/cinnamon_rowll")
toptext.place(x = (500/2)-150 ,y = 5)

infotextPositionX = (500/2)-240
infotext = tk.Label(root, text = "Select the foler you want your data to be stored in :")
infotext.place(x = (500/2)-240, y = 30) 


field = tk.Entry(root)
field.place(x = (500/2), y = 25)

# Create a button to browse for a folder
browse_button = tk.Button(root, text="Browse", command=browse_folder)
browse_button.grid(row = 2, column = 5, pady = 2)

# Create a scrollbar for the Listbox

# Start the Tkinter main loop'''
root.mainloop()
