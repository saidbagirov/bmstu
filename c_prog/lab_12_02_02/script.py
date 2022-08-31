import tkinter as tk
import fib



class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master, width=512, height=512)
        self.master = master
        self.pack(fill=tk.BOTH, expand=1)
        #self.grid_rowconfigure(5, weight=1)
        self.grid_columnconfigure(0, weight=1)
        self.create_widgets()

    def create_widgets(self):
        self.label1 = tk.Label(self, text="Fibonacci numbers count")
        self.label1.grid(sticky=tk.N + tk.W)

        self.counter_sv = tk.StringVar()

        self.fib_counter = tk.Spinbox(self, from_=1, to=100, textvariable=self.counter_sv)
        self.fib_counter.grid(sticky=tk.N + tk.W + tk.E)
        
        self.counter_sv.trace("w", lambda name, index, mode, sv=self.counter_sv: self.calc_fib())


        self.label2 = tk.Label(self, text="Fibonacci numbers")
        self.label2.grid(sticky=tk.N + tk.W)

        self.fib_text = tk.Entry(self) #, state=tk.DISABLED
        self.fib_text.grid(sticky=tk.N + tk.W + tk.E)


        self.label2 = tk.Label(self, text="Source array")
        self.label2.grid(sticky=tk.N + tk.W)

        self.src_sv = tk.StringVar()
        self.src_sv.trace("w", lambda name, index, mode, sv=self.src_sv: self.calc_unique())

        self.src_array = tk.Entry(self, textvariable=self.src_sv)
        self.src_array.grid(sticky=tk.N + tk.W + tk.E)


        self.label2 = tk.Label(self, text="Result array")
        self.label2.grid(sticky=tk.N + tk.W)

        self.dst_array = tk.Entry(self) #, state=tk.DISABLED
        self.dst_array.grid(sticky=tk.N + tk.W + tk.E)


    def calc_fib(self):
        fibs = ""
        for v in fib.fill_fib(int(self.fib_counter.get())):
            fibs += str(v) + " "
        #self.fib_text.configure(state=tk.NORMAL)
        self.fib_text.delete(0, tk.END)
        self.fib_text.insert(0, fibs)
        #self.fib_text.configure(state=tk.DISABLED)


    def calc_unique(self):
        try:
            src = [int(v) for v in self.src_array.get().split()]
            
            dst = ""
            for v in fib.copy_unique(src):
                dst += str(v) + " "

            self.dst_array.delete(0, tk.END)
            self.dst_array.insert(0, dst)

        except:
            self.dst_array.delete(0, tk.END)
            self.dst_array.insert(0, "ERROR")


root = tk.Tk()
app = Application(master=root)
app.mainloop()

#print(fib.fill_fib(10))
#print(fib.copy_unique([1, 2, 3, 3, -1, 2, -1, 0]))