from archicad import ACConnection

conn = ACConnection.connect()
assert conn
acc = conn.commands
act = conn.types


bCheckConnection = acc.IsAlive()
print("Connections is alive?: ", bCheckConnection)

addOnCommand = act.AddOnCommandId ('ZuruTech', 'IFCExport')
bCheckAddon = acc.IsAddOnCommandAvailable(addOnCommand)
print("Addon is availible?: ", bCheckAddon)

if(bCheckAddon):
    print("Run commandName: IFCExport from commandNamespace: ZuruTech")
    response = acc.ExecuteAddOnCommand (addOnCommand)
    print (response)