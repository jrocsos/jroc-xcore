from CORE.jroc_master import JROCMaster



JROC = JROCMaster()



systems = [

    "Brain",

    "Swarm",

    "Memory",

    "Evolution",

    "City",

    "Governance",

    "Missions",

    "Tools",

    "Intelligence"

]



for system in systems:

    JROC.connect(system)



print(
JROC.boot()
)


print(
"\nSYSTEM CONNECTIONS"
)


print(
JROC.health()
)


print(
"\nEVOLUTION"
)


print(
JROC.upgrade("v100")
)
