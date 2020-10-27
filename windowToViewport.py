def WindowtoViewport(x_w, y_w, x_wmax, y_wmax,
                     x_wmin, y_wmin, x_vmax,
                     y_vmax, x_vmin, y_vmin):

    # point on viewport
    # calculatng Sx and Sy
    sx = (x_vmax - x_vmin) / (x_wmax - x_wmin)
    sy = (y_vmax - y_vmin) / (y_wmax - y_wmin)

    # calculating the point on viewport
    x_v = x_vmin + ((x_w - x_wmin) * sx)
    y_v = y_vmin + ((y_w - y_wmin) * sy)

    print("The point on viewport:(", int(x_v),
          ",", int(y_v), ")")


# Driver Code
if __name__ == '__main__':

    # boundary values for window
    x_wmax = 80
    y_wmax = 80
    x_wmin = 20
    y_wmin = 40

    # boundary values for viewport
    x_vmax = 60
    y_vmax = 60
    x_vmin = 30
    y_vmin = 40

    # point on window
    x_w = 30
    y_w = 80

    WindowtoViewport(30, 80, 80, 80, 20, 40, 60, 60, 30, 40)
