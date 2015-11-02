void ternarysynth(int *in, int *out)
{
#pragma AP interface ap_fifo port=in
#pragma AP interface ap_fifo port=out
#pragma AP interface ap_ctrl_none port=return
    *out = (*in < 0) ? 42 : 37;
}
