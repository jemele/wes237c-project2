void ifsynth(int *in, int *out)
{
#pragma AP interface ap_fifo port=in
#pragma AP interface ap_fifo port=out
#pragma AP interface ap_ctrl_none port=return
    if (*in < 0) {
        *out = 42;
    } else {
        *out = 37;
    }
}
