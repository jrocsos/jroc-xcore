from evolution.version_manager import JROCVersionManager


jroc_evolution = JROCVersionManager()


print(
    jroc_evolution.status()
)


for i in range(5):

    print(
        jroc_evolution.upgrade()
    )
