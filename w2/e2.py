import re


def give_first_value_in_column(filename, columname):
    try:
        with open(file=file_name, mode="r") as f:
            # read whole file
            f_content = f.read()
            # split into array of strings with the endline chars
            lines = f_content.split("\n")

            target_index = -1
            # iterate over all lines
            for n, line in enumerate(lines):
                # check if columname is found

                if (loc := line.find(col_name)) != -1:
                    # found columnname, inded is stored
                    target_index = loc
                    # only lines after one containing columname are sotred
                    rest_lines = lines[n+1:]

            if target_index != -1:
                # columname was located
                for line in rest_lines:
                    # check for line with numeric entry underneath columname
                    if line[target_index].isnumeric():
                        # matching for any form of a number
                        target = re.match(
                            r"\A\d*.{0,1}\d*", line[target_index:])
                        if target:
                            return target.group(0)
            else:
                print(f"No {col_name} column in {file_name} found")
        f.close()
    except FileNotFoundError:
        raise FileExistsError
    except Exception as e:
        print(e)
        raise Exception
    return


if __name__ == "__main__":
    # assuming value is stored underneath the columname, starting on the same index in separate lines
    file_name = "brilcalc.log"
    col_name = "totrecorded(/pb)"

    lum = float(give_first_value_in_column(file_name, col_name))
    lum /= 1000
    print(f"{lum:.1f} fb^-1")
