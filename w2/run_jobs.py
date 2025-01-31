import os
import subprocess
from concurrent.futures import ThreadPoolExecutor

def run_job(i):
    # run on linux, for windows .\e1.exe ...
    cmd = f"./e1.exe {i} > python_output_{i}.txt"
    subprocess.run(cmd, shell=True, stdout= False)
        

if __name__ == "__main__":
    os.system("make")

    with ThreadPoolExecutor(max_workers=10) as executor:
        executor.map(run_job, range(11, 21))

    print("all python jobs finished")