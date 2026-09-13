from brain.kernel import JROCKernel


jroc = JROCKernel()



print(
"BOOTING JROC AI"
)



print(
jroc.boot()
)



print(
"\nSYSTEM STATUS"
)



print(
jroc.status_report()
)



print(
"\nUPGRADING SYSTEM"
)



for i in range(5):

    print(
        jroc.upgrade()
    )



print(
"\nFINAL STATUS"
)



print(
jroc.status_report()
)
