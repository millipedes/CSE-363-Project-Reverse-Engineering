// WARNING: Could not reconcile some variable overlaps

long dbg.main(void)

{
    ulong uVar1;
    int64_t in_FS_OFFSET;
    ulong data;
    uint var_18h;
    uint var_14h;
    uint var_10h;
    int64_t canary;
    
    canary = *(in_FS_OFFSET + 0x28);
    data._0_4_ = 0xfffffffe;
    data._4_4_ = 0x2d;
    var_18h = 0;
    var_14h = 0xb;
    var_10h = 0xfffffff7;
    dbg.bubbleSort(&data, 5);
    sym.imp.puts("Sorted Array in Ascending Order:");
    dbg.printArray(&data, 5);
    uVar1 = 0;
    if (canary != *(in_FS_OFFSET + 0x28)) {
        uVar1 = sym.imp.__stack_chk_fail();
    }
    return uVar1;
}
/*[0x000012f9]> s sym.bubbleSort
[0x000011a9]> pdg
*/
// WARNING: Could not reconcile some variable overlaps

void dbg.bubbleSort(int64_t arg1, ulong arg2)

{
    uint uVar1;
    ulong array;
    ulong step;
    
    for (step._0_4_ = 0; step < arg2 + -1; step._0_4_ = step + 1) {
        for (step._4_4_ = 0; step._4_4_ < (arg2 - step) + -1; step._4_4_ = step._4_4_ + 1) {
            if (*(arg1 + (step._4_4_ + 1) * 4) < *(arg1 + step._4_4_ * 4)) {
                uVar1 = *(arg1 + step._4_4_ * 4);
                *(arg1 + step._4_4_ * 4) = *(arg1 + (step._4_4_ + 1) * 4);
                *((step._4_4_ + 1) * 4 + arg1) = uVar1;
            }
        }
    }
    return;
}

