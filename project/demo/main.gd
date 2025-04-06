extends Control

@onready var network_table_instance: NetworkTableInstance = $NetworkTableInstance


func _ready() -> void:
	network_table_instance.set_server("localhost")
	network_table_instance.start_ds_client()
	network_table_instance.start_client_4("Godot NetworkTables Demo")
