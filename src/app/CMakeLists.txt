## TODO: restructure target + modulize

# configure_file(${CMAKE_CURRENT_SOURCE_DIR}/includes.h.in includes.h)
# TODO: hardcoded path
# TODO: verify
configure_file(${CMAKE_SOURCE_DIR}/language_packages.h.in language_packages.h)
configure_file(${CMAKE_SOURCE_DIR}/productVersion.h.in productVersion.h)
# configure_file(${CMAKE_SOURCE_DIR}/version.txt.in version.txt)
configure_file(${CMAKE_SOURCE_DIR}/productVersion.h.in productVersion.h)
configure_file(${CMAKE_SOURCE_DIR}/language_packages.h.in language_packages.h)

set(CMAKE_AUTOMOC ON)

add_executable(source-inspector)
## Ensure that indexer is build before 'source-inspector'
add_dependencies(source-inspector indexer)

# TODO: not a good practice at all
target_include_directories(source-inspector PRIVATE
		codeblocks
		commandline
		commandline/commands
		component
		component/controller
		component/controller/helper
		component/view
		component/view/helper
		data
		data/bookmark
		data/fulltextsearch
		data/graph
		data/graph/token_component
		data/indexer
		data/indexer/interprocess
		data/indexer/interprocess/shared_types
		data/location
		data/name
		data/parser
		data/parser/cxx
		data/parser/cxx/name
		data/parser/cxx/name_resolver
		data/search
		data/storage
		data/storage/migration
		data/storage/sqlite
		data/storage/type
		data/tooltip
		file
		interprocess
		logging
		math
		messaging
		messaging/filter_types
		messaging/type
		messaging/type/activation
		messaging/type/bookmark
		messaging/type/code
		messaging/type/custom_trail
		messaging/type/error
		messaging/type/focus
		messaging/type/graph
		messaging/type/history
		messaging/type/indexing
		messaging/type/plugin
		messaging/type/search
		messaging/type/tab
		migration
		path_detector
		path_detector/cxx_header
		paths
		project
		qt
		qt/element
		qt/element/bookmark
		qt/element/button
		qt/element/code
		qt/element/dialog
		qt/element/history
		qt/element/search
		qt/graphics
		qt/graphics/base
		qt/graphics/component
		qt/graphics/graph
		qt/network
		qt/project_wizard
		qt/project_wizard/content
		qt/project_wizard/content/path
		qt/project_wizard/content/paths
		qt/utility
		qt/view
		qt/window
		scheduling
		settings
		settings/migration
		settings/source_group
		settings/source_group/component
		settings/source_group/component/cxx
		settings/source_group/type
		text
		utility
		${CMAKE_CURRENT_LIST_DIR}
		${CMAKE_CURRENT_BINARY_DIR}
		# ${LLVM_INCLUDE_DIRS}
		# ${CLANG_INCLUDE_DIRS}
		# TODO: hardcoded path + outside target scope
		${CMAKE_SOURCE_DIR}/src/external/sqlite
)

target_sources(source-inspector PRIVATE
		Application.cpp
		Application.h
		ApplicationArchitectureType.h
		CompilationDatabase.cpp
		CompilationDatabase.h
		ConfigManager.cpp
		ConfigManager.h
		IncludeDirective.cpp
		IncludeDirective.h
		IncludeProcessing.cpp
		IncludeProcessing.h
		LanguagePackage.h
		LanguagePackageCxx.cpp
		LanguagePackageCxx.h
		LanguagePackageManager.cpp
		LanguagePackageManager.h
		LowMemoryStringMap.h
		main.cpp
		Optional.h
		OrderedCache.h
		OsType.h
		Property.h
		ScopedFunctor.cpp
		ScopedFunctor.h
		SingleValueCache.h
		Status.h
		TimeStamp.cpp
		TimeStamp.h
		tracing.cpp
		tracing.h
		Tree.h
		types.h
		UnorderedCache.h
		# TODO: there is a lot 'utility' code -> find meaningful names
		utility.cpp
		utility.h
		utilityApp.cpp
		utilityApp.h
		utilityLibrary.h
		utilityPathDetection.cpp
		utilityPathDetection.h
		utilityUuid.cpp
		utilityUuid.h
		utilityWindows.cpp
		utilityWindows.h
		utilityXml.cpp
		utilityXml.h
		Version.cpp
		Version.h

		codeblocks/CodeblocksCompiler.cpp
		codeblocks/CodeblocksCompiler.h
		codeblocks/CodeblocksCompilerVarType.cpp
		codeblocks/CodeblocksCompilerVarType.h
		codeblocks/CodeblocksProject.cpp
		codeblocks/CodeblocksProject.h
		codeblocks/CodeblocksTarget.cpp
		codeblocks/CodeblocksTarget.h
		codeblocks/CodeblocksTargetRelationType.cpp
		codeblocks/CodeblocksTargetRelationType.h
		codeblocks/CodeblocksUnit.cpp
		codeblocks/CodeblocksUnit.h

		commandline/CommandlineHelper.cpp
		commandline/CommandlineHelper.h
		commandline/CommandLineParser.cpp
		commandline/CommandLineParser.h
		commandline/commands/CommandlineCommand.cpp
		commandline/commands/CommandlineCommand.h
		commandline/commands/CommandlineCommandConfig.cpp
		commandline/commands/CommandlineCommandConfig.h
		commandline/commands/CommandlineCommandIndex.cpp
		commandline/commands/CommandlineCommandIndex.h

		component/controller/helper/ActivationListener.cpp
		component/controller/helper/ActivationListener.h
		component/controller/helper/BucketLayouter.cpp
		component/controller/helper/BucketLayouter.h
		component/controller/helper/DummyEdge.h
		component/controller/helper/DummyNode.h
		component/controller/helper/ListLayouter.cpp
		component/controller/helper/ListLayouter.h
		component/controller/helper/NetworkProtocolHelper.cpp
		component/controller/helper/NetworkProtocolHelper.h
		component/controller/helper/ScreenSearchInterfaces.h
		component/controller/helper/SnippetMerger.cpp
		component/controller/helper/SnippetMerger.h
		component/controller/helper/TrailLayouter.cpp
		component/controller/helper/TrailLayouter.h

		component/controller/ActivationController.cpp
		component/controller/ActivationController.h
		component/controller/BookmarkController.cpp
		component/controller/BookmarkController.h
		component/controller/CodeController.cpp
		component/controller/CodeController.h
		component/controller/Controller.cpp
		component/controller/Controller.h
		component/controller/CustomTrailController.cpp
		component/controller/CustomTrailController.h
		component/controller/ErrorController.cpp
		component/controller/ErrorController.h
		component/controller/GraphController.cpp
		component/controller/GraphController.h
		component/controller/IDECommunicationController.cpp
		component/controller/IDECommunicationController.h
		component/controller/RefreshController.cpp
		component/controller/RefreshController.h
		component/controller/ScreenSearchController.cpp
		component/controller/ScreenSearchController.h
		component/controller/SearchController.cpp
		component/controller/SearchController.h
		component/controller/StatusBarController.cpp
		component/controller/StatusBarController.h
		component/controller/StatusController.cpp
		component/controller/StatusController.h
		component/controller/TabsController.cpp
		component/controller/TabsController.h
		component/controller/TooltipController.cpp
		component/controller/TooltipController.h
		component/controller/UndoRedoController.cpp
		component/controller/UndoRedoController.h

		component/view/helper/CodeScrollParams.h
		component/view/helper/CodeSnippetParams.cpp
		component/view/helper/CodeSnippetParams.h
		component/view/BookmarkButtonsView.cpp
		component/view/BookmarkButtonsView.h
		component/view/BookmarkView.cpp
		component/view/BookmarkView.h
		component/view/CodeView.cpp
		component/view/CodeView.h
		component/view/CompositeView.cpp
		component/view/CompositeView.h
		component/view/CustomTrailView.h
		component/view/DialogView.cpp
		component/view/DialogView.h
		component/view/ErrorView.cpp
		component/view/ErrorView.h
		component/view/GraphView.cpp
		component/view/GraphView.h
		component/view/GraphViewStyle.cpp
		component/view/GraphViewStyle.h
		component/view/GraphViewStyleImpl.h
		component/view/MainView.cpp
		component/view/MainView.h
		component/view/RefreshView.cpp
		component/view/RefreshView.h
		component/view/ScreenSearchView.cpp
		component/view/ScreenSearchView.h
		component/view/SearchView.cpp
		component/view/SearchView.h
		component/view/StatusBarView.cpp
		component/view/StatusBarView.h
		component/view/StatusView.cpp
		component/view/StatusView.h
		component/view/TabbedView.cpp
		component/view/TabbedView.h
		component/view/TabsView.cpp
		component/view/TabsView.h
		component/view/TooltipView.cpp
		component/view/TooltipView.h
		component/view/UndoRedoView.cpp
		component/view/UndoRedoView.h
		component/view/View.cpp
		component/view/View.h
		component/view/ViewFactory.h
		component/view/ViewLayout.cpp
		component/view/ViewLayout.h
		component/view/ViewWidgetWrapper.cpp
		component/view/ViewWidgetWrapper.h

		component/Component.cpp
		component/Component.h
		component/ComponentFactory.cpp
		component/ComponentFactory.h
		component/ComponentManager.cpp
		component/ComponentManager.h
		component/NetworkFactory.cpp
		component/NetworkFactory.h
		component/Tab.cpp
		component/Tab.h
		component/TabId.cpp
		component/TabId.h

		data/bookmark/Bookmark.cpp
		data/bookmark/Bookmark.h
		data/bookmark/BookmarkCategory.cpp
		data/bookmark/BookmarkCategory.h
		data/bookmark/EdgeBookmark.cpp
		data/bookmark/EdgeBookmark.h
		data/bookmark/NodeBookmark.cpp
		data/bookmark/NodeBookmark.h

		data/fulltextsearch/FullTextSearchIndex.cpp
		data/fulltextsearch/FullTextSearchIndex.h
		data/fulltextsearch/SuffixArray.cpp
		data/fulltextsearch/SuffixArray.h

		data/graph/token_component/TokenComponent.cpp
		data/graph/token_component/TokenComponent.h
		data/graph/token_component/TokenComponentAbstraction.cpp
		data/graph/token_component/TokenComponentAbstraction.h
		data/graph/token_component/TokenComponentAccess.cpp
		data/graph/token_component/TokenComponentAccess.h
		data/graph/token_component/TokenComponentBundledEdges.cpp
		data/graph/token_component/TokenComponentBundledEdges.h
		data/graph/token_component/TokenComponentConst.cpp
		data/graph/token_component/TokenComponentConst.h
		data/graph/token_component/TokenComponentFilePath.cpp
		data/graph/token_component/TokenComponentFilePath.h
		data/graph/token_component/TokenComponentInheritanceChain.h
		data/graph/token_component/TokenComponentIsAmbiguous.h
		data/graph/token_component/TokenComponentStatic.cpp
		data/graph/token_component/TokenComponentStatic.h

		data/graph/Edge.cpp
		data/graph/Edge.h
		data/graph/ElementComponentKind.cpp
		data/graph/ElementComponentKind.h
		data/graph/Graph.cpp
		data/graph/Graph.h
		data/graph/Node.cpp
		data/graph/Node.h
		data/graph/Token.cpp
		data/graph/Token.h

		data/indexer/interprocess/shared_types/SharedIndexerCommand.cpp
		data/indexer/interprocess/shared_types/SharedIndexerCommand.h
		data/indexer/interprocess/shared_types/SharedIntermediateStorage.cpp
		data/indexer/interprocess/shared_types/SharedIntermediateStorage.h
		data/indexer/interprocess/shared_types/SharedStorageTypes.h

		data/indexer/interprocess/BaseInterprocessDataManager.cpp
		data/indexer/interprocess/BaseInterprocessDataManager.h
		data/indexer/interprocess/InterprocessIndexer.cpp
		data/indexer/interprocess/InterprocessIndexer.h
		data/indexer/interprocess/InterprocessIndexerCommandManager.cpp
		data/indexer/interprocess/InterprocessIndexerCommandManager.h
		data/indexer/interprocess/InterprocessIndexingStatusManager.cpp
		data/indexer/interprocess/InterprocessIndexingStatusManager.h
		data/indexer/interprocess/InterprocessIntermediateStorageManager.cpp
		data/indexer/interprocess/InterprocessIntermediateStorageManager.h

		data/indexer/CombinedIndexerCommandProvider.cpp
		data/indexer/CombinedIndexerCommandProvider.h
		data/indexer/Indexer.h
		data/indexer/IndexerBase.cpp
		data/indexer/IndexerBase.h
		data/indexer/IndexerCommand.cpp
		data/indexer/IndexerCommand.h
		data/indexer/IndexerCommandCustom.cpp
		data/indexer/IndexerCommandCustom.h
		data/indexer/IndexerCommandProvider.cpp
		data/indexer/IndexerCommandProvider.h
		data/indexer/IndexerCommandType.cpp
		data/indexer/IndexerCommandType.h
		data/indexer/IndexerComposite.cpp
		data/indexer/IndexerComposite.h
		data/indexer/IndexerStateInfo.h
		data/indexer/MemoryIndexerCommandProvider.cpp
		data/indexer/MemoryIndexerCommandProvider.h
		data/indexer/TaskBuildIndex.cpp
		data/indexer/TaskBuildIndex.h
		data/indexer/TaskExecuteCustomCommands.cpp
		data/indexer/TaskExecuteCustomCommands.h
		data/indexer/TaskFillIndexerCommandQueue.cpp
		data/indexer/TaskFillIndexerCommandQueue.h
		data/indexer/CxxIndexerCommandProvider.cpp
		data/indexer/CxxIndexerCommandProvider.h
		data/indexer/IndexerCommandCxx.cpp
		data/indexer/IndexerCommandCxx.h
		data/indexer/IndexerCxx.cpp
		data/indexer/IndexerCxx.h

		data/location/LocationType.cpp
		data/location/LocationType.h
		data/location/SourceLocation.cpp
		data/location/SourceLocation.h
		data/location/SourceLocationCollection.cpp
		data/location/SourceLocationCollection.h
		data/location/SourceLocationFile.cpp
		data/location/SourceLocationFile.h

		data/name/NameDelimiterType.cpp
		data/name/NameDelimiterType.h
		data/name/NameElement.cpp
		data/name/NameElement.h
		data/name/NameHierarchy.cpp
		data/name/NameHierarchy.h

		data/parser/AccessKind.cpp
		data/parser/AccessKind.h
		data/parser/ParseLocation.cpp
		data/parser/ParseLocation.h
		data/parser/Parser.cpp
		data/parser/Parser.h
		data/parser/ParserClient.h
		data/parser/ParserClientImpl.cpp
		data/parser/ParserClientImpl.h
		data/parser/ReferenceKind.cpp
		data/parser/ReferenceKind.h
		data/parser/SymbolKind.cpp
		data/parser/SymbolKind.h
		data/parser/TaskParseWrapper.cpp
		data/parser/TaskParseWrapper.h

		data/parser/cxx/name/CxxDeclName.cpp
		data/parser/cxx/name/CxxDeclName.h
		data/parser/cxx/name/CxxFunctionDeclName.cpp
		data/parser/cxx/name/CxxFunctionDeclName.h
		data/parser/cxx/name/CxxName.cpp
		data/parser/cxx/name/CxxName.h
		data/parser/cxx/name/CxxQualifierFlags.cpp
		data/parser/cxx/name/CxxQualifierFlags.h
		data/parser/cxx/name/CxxStaticFunctionDeclName.cpp
		data/parser/cxx/name/CxxStaticFunctionDeclName.h
		data/parser/cxx/name/CxxTypeName.cpp
		data/parser/cxx/name/CxxTypeName.h
		data/parser/cxx/name/CxxVariableDeclName.cpp
		data/parser/cxx/name/CxxVariableDeclName.h

		data/parser/cxx/name_resolver/CxxDeclNameResolver.cpp
		data/parser/cxx/name_resolver/CxxDeclNameResolver.h
		data/parser/cxx/name_resolver/CxxNameResolver.cpp
		data/parser/cxx/name_resolver/CxxNameResolver.h
		data/parser/cxx/name_resolver/CxxSpecifierNameResolver.cpp
		data/parser/cxx/name_resolver/CxxSpecifierNameResolver.h
		data/parser/cxx/name_resolver/CxxTemplateArgumentNameResolver.cpp
		data/parser/cxx/name_resolver/CxxTemplateArgumentNameResolver.h
		data/parser/cxx/name_resolver/CxxTemplateParameterStringResolver.cpp
		data/parser/cxx/name_resolver/CxxTemplateParameterStringResolver.h
		data/parser/cxx/name_resolver/CxxTypeNameResolver.cpp
		data/parser/cxx/name_resolver/CxxTypeNameResolver.h

		data/parser/cxx/ASTAction.cpp
		data/parser/cxx/ASTAction.h
		data/parser/cxx/ASTConsumer.cpp
		data/parser/cxx/ASTConsumer.h
		data/parser/cxx/CanonicalFilePathCache.cpp
		data/parser/cxx/CanonicalFilePathCache.h
		data/parser/cxx/CommentHandler.cpp
		data/parser/cxx/CommentHandler.h
		data/parser/cxx/ClangInvocationInfo.cpp
		data/parser/cxx/ClangInvocationInfo.h
		data/parser/cxx/CxxAstVisitor.cpp
		data/parser/cxx/CxxAstVisitor.h
		data/parser/cxx/CxxAstVisitorComponent.cpp
		data/parser/cxx/CxxAstVisitorComponent.h
		data/parser/cxx/CxxAstVisitorComponentBraceRecorder.cpp
		data/parser/cxx/CxxAstVisitorComponentBraceRecorder.h
		data/parser/cxx/CxxAstVisitorComponentContext.cpp
		data/parser/cxx/CxxAstVisitorComponentContext.h
		data/parser/cxx/CxxAstVisitorComponentDeclRefKind.cpp
		data/parser/cxx/CxxAstVisitorComponentDeclRefKind.h
		data/parser/cxx/CxxAstVisitorComponentImplicitCode.cpp
		data/parser/cxx/CxxAstVisitorComponentImplicitCode.h
		data/parser/cxx/CxxAstVisitorComponentIndexer.cpp
		data/parser/cxx/CxxAstVisitorComponentIndexer.h
		data/parser/cxx/CxxAstVisitorComponentTypeRefKind.cpp
		data/parser/cxx/CxxAstVisitorComponentTypeRefKind.h
		data/parser/cxx/CxxCompilationDatabaseSingle.cpp
		data/parser/cxx/CxxCompilationDatabaseSingle.h
		data/parser/cxx/CxxContext.cpp
		data/parser/cxx/CxxContext.h
		data/parser/cxx/CxxDiagnosticConsumer.cpp
		data/parser/cxx/CxxDiagnosticConsumer.h
		data/parser/cxx/CxxParser.cpp
		data/parser/cxx/CxxParser.h
		data/parser/cxx/CxxVerboseAstVisitor.cpp
		data/parser/cxx/CxxVerboseAstVisitor.h
		data/parser/cxx/GeneratePCHAction.cpp
		data/parser/cxx/GeneratePCHAction.h
		data/parser/cxx/PreprocessorCallbacks.cpp
		data/parser/cxx/PreprocessorCallbacks.h
		data/parser/cxx/SingleFrontendActionFactory.cpp
		data/parser/cxx/SingleFrontendActionFactory.h
		data/parser/cxx/utilityClang.cpp
		data/parser/cxx/utilityClang.h

		data/search/SearchIndex.cpp
		data/search/SearchIndex.h
		data/search/SearchMatch.cpp
		data/search/SearchMatch.h

		data/storage/migration/SqliteStorageMigration.cpp
		data/storage/migration/SqliteStorageMigration.h
		data/storage/migration/SqliteStorageMigrationLambda.cpp
		data/storage/migration/SqliteStorageMigrationLambda.h
		data/storage/migration/SqliteStorageMigrator.h

		data/storage/sqlite/SqliteBookmarkStorage.cpp
		data/storage/sqlite/SqliteBookmarkStorage.h
		data/storage/sqlite/SqliteDatabaseIndex.cpp
		data/storage/sqlite/SqliteDatabaseIndex.h
		data/storage/sqlite/SqliteIndexStorage.cpp
		data/storage/sqlite/SqliteIndexStorage.h
		data/storage/sqlite/SqliteStorage.cpp
		data/storage/sqlite/SqliteStorage.h

		data/storage/type/StorageBookmarkCategory.h
		data/storage/type/StorageBookmark.h
		data/storage/type/StorageBookmarkedEdge.h
		data/storage/type/StorageBookmarkedNode.h
		data/storage/type/StorageComponentAccess.h
		data/storage/type/StorageEdge.h
		data/storage/type/StorageElementComponent.h
		data/storage/type/StorageError.h
		data/storage/type/StorageFile.h
		data/storage/type/StorageLocalSymbol.h
		data/storage/type/StorageNode.h
		data/storage/type/StorageOccurrence.h
		data/storage/type/StorageSourceLocation.h
		data/storage/type/StorageSymbol.h

		data/storage/IntermediateStorage.cpp
		data/storage/IntermediateStorage.h
		data/storage/PersistentStorage.cpp
		data/storage/PersistentStorage.h
		data/storage/Storage.cpp
		data/storage/Storage.h
		data/storage/StorageAccess.h
		data/storage/StorageAccessProxy.cpp
		data/storage/StorageAccessProxy.h
		data/storage/StorageCache.cpp
		data/storage/StorageCache.h
		data/storage/StorageProvider.cpp
		data/storage/StorageProvider.h
		data/storage/StorageStats.h

		data/tooltip/TooltipInfo.h
		data/tooltip/TooltipOrigin.h

		data/DefinitionKind.cpp
		data/DefinitionKind.h
		data/ErrorCountInfo.h
		data/ErrorFilter.h
		data/ErrorInfo.h
		data/GroupType.cpp
		data/GroupType.h
		data/HierarchyCache.cpp
		data/HierarchyCache.h
		data/NodeKind.cpp
		data/NodeKind.h
		data/NodeType.cpp
		data/NodeType.h
		data/NodeTypeSet.cpp
		data/NodeTypeSet.h
		data/TaskCleanStorage.cpp
		data/TaskCleanStorage.h
		data/TaskFinishParsing.cpp
		data/TaskFinishParsing.h
		data/TaskInjectStorage.cpp
		data/TaskInjectStorage.h
		data/TaskMergeStorages.cpp
		data/TaskMergeStorages.h

		file/FileInfo.cpp
		file/FileInfo.h
		file/FileManager.cpp
		file/FileManager.h
		file/FilePath.cpp
		file/FilePath.h
		file/FilePathFilter.cpp
		file/FilePathFilter.h
		file/FileRegister.cpp
		file/FileRegister.h
		file/FileSystem.cpp
		file/FileSystem.h
		file/FileTree.cpp
		file/FileTree.h
		file/utilityFile.cpp
		file/utilityFile.h

		interprocess/SharedMemory.cpp
		interprocess/SharedMemory.h
		interprocess/SharedMemoryGarbageCollector.cpp
		interprocess/SharedMemoryGarbageCollector.h

		logging/ConsoleLogger.cpp
		logging/ConsoleLogger.h
		logging/FileLogger.cpp
		logging/FileLogger.h
		logging/Logger.cpp
		logging/Logger.h
		logging/logging.h
		logging/LogManager.cpp
		logging/LogManager.h
		logging/LogManagerImplementation.cpp
		logging/LogManagerImplementation.h
		logging/LogMessage.h

		math/Color.h
		math/MatrixBase.h
		math/MatrixDynamicBase.h
		math/Vector2.h
		math/Vector4.h
		math/VectorBase.h

		messaging/filter_types/MessageFilterErrorCountUpdate.h
		messaging/filter_types/MessageFilterFocusInOut.h
		messaging/filter_types/MessageFilterSearchAutocomplete.h

		messaging/type/activation/MessageActivateBase.h
		messaging/type/activation/MessageActivateErrors.h
		messaging/type/activation/MessageActivateFullTextSearch.h
		messaging/type/activation/MessageActivateLegend.h
		messaging/type/activation/MessageActivateOverview.h
		messaging/type/activation/MessageActivateTokens.h
		messaging/type/activation/MessageActivateTrail.h

		messaging/type/bookmark/MessageBookmarkActivate.h
		messaging/type/bookmark/MessageBookmarkBrowse.h
		messaging/type/bookmark/MessageBookmarkButtonState.h
		messaging/type/bookmark/MessageBookmarkCreate.h
		messaging/type/bookmark/MessageBookmarkDelete.h
		messaging/type/bookmark/MessageBookmarkEdit.h

		messaging/type/code/MessageActivateFile.h
		messaging/type/code/MessageActivateLocalSymbols.h
		messaging/type/code/MessageActivateSourceLocations.h
		messaging/type/code/MessageActivateTokenIds.h
		messaging/type/code/MessageChangeFileView.h
		messaging/type/code/MessageCodeReference.h
		messaging/type/code/MessageCodeShowDefinition.h
		messaging/type/code/MessageScrollCode.h
		messaging/type/code/MessageScrollToLine.h
		messaging/type/code/MessageShowReference.h
		messaging/type/code/MessageShowScope.h

		messaging/type/custom_trail/MessageCustomTrailShow.h

		messaging/type/error/MessageErrorCountClear.h
		messaging/type/error/MessageErrorCountUpdate.h
		messaging/type/error/MessageErrorsAll.h
		messaging/type/error/MessageErrorsForFile.h
		messaging/type/error/MessageErrorsHelpMessage.h
		messaging/type/error/MessageShowError.h

		messaging/type/focus/MessageFocusChanged.h
		messaging/type/focus/MessageFocusedSearchView.h
		messaging/type/focus/MessageFocusIn.h
		messaging/type/focus/MessageFocusOut.h
		messaging/type/focus/MessageFocusView.h

		messaging/type/graph/MessageActivateEdge.h
		messaging/type/graph/MessageActivateNodes.h
		messaging/type/graph/MessageActivateTrailEdge.h
		messaging/type/graph/MessageDeactivateEdge.h
		messaging/type/graph/MessageGraphNodeBundleSplit.h
		messaging/type/graph/MessageGraphNodeExpand.h
		messaging/type/graph/MessageGraphNodeHide.h
		messaging/type/graph/MessageGraphNodeMove.h
		messaging/type/graph/MessageScrollGraph.h
		messaging/type/graph/MessageSaveAsImage.h

		messaging/type/history/MessageHistoryToPosition.h
		messaging/type/history/MessageHistoryRedo.h
		messaging/type/history/MessageHistoryUndo.h

		messaging/type/indexing/MessageIndexingFinished.h
		messaging/type/indexing/MessageIndexingInterrupted.h
		messaging/type/indexing/MessageIndexingShowDialog.h
		messaging/type/indexing/MessageIndexingStarted.h
		messaging/type/indexing/MessageIndexingStatus.h

		messaging/type/plugin/MessageIDECreateCDB.h
		messaging/type/plugin/MessageMoveIDECursor.h
		messaging/type/plugin/MessagePingReceived.h
		messaging/type/plugin/MessagePluginPortChange.h

		messaging/type/search/MessageFind.h
		messaging/type/search/MessageSearch.h
		messaging/type/search/MessageSearchAutocomplete.h

		messaging/type/tab/MessageTabClose.h
		messaging/type/tab/MessageTabOpen.h
		messaging/type/tab/MessageTabOpenWith.h
		messaging/type/tab/MessageTabSelect.h
		messaging/type/tab/MessageTabState.h

		messaging/type/MessageActivateWindow.h
		messaging/type/MessageClearStatusView.h
		messaging/type/MessageCloseProject.h
		messaging/type/MessageFlushUpdates.h
		messaging/type/MessageLoadProject.h
		messaging/type/MessageLogFilterChanged.h
		messaging/type/MessageProjectEdit.h
		messaging/type/MessageProjectNew.h
		messaging/type/MessageQuitApplication.h
		messaging/type/MessageRefresh.h
		messaging/type/MessageRefreshUI.h
		messaging/type/MessageRefreshUIState.h
		messaging/type/MessageResetZoom.h
		messaging/type/MessageShowStatus.h
		messaging/type/MessageStatus.cpp
		messaging/type/MessageStatus.h
		messaging/type/MessageStatusFilterChanged.h
		messaging/type/MessageSwitchColorScheme.h
		messaging/type/MessageTooltipHide.h
		messaging/type/MessageTooltipShow.h
		messaging/type/MessageWindowChanged.h
		messaging/type/MessageWindowClosed.h
		messaging/type/MessageWindowFocus.h
		messaging/type/MessageZoom.h

		messaging/Message.h
		messaging/MessageBase.cpp
		messaging/MessageBase.h
		messaging/MessageFilter.h
		messaging/MessageListener.h
		messaging/MessageListenerBase.cpp
		messaging/MessageListenerBase.h
		messaging/MessageQueue.cpp
		messaging/MessageQueue.h

		migration/Migration.h
		migration/Migrator.h

		path_detector/cxx_header/CxxFrameworkPathDetector.cpp
		path_detector/cxx_header/CxxFrameworkPathDetector.h
		path_detector/cxx_header/CxxHeaderPathDetector.cpp
		path_detector/cxx_header/CxxHeaderPathDetector.h
		path_detector/cxx_header/CxxVs10To14HeaderPathDetector.cpp
		path_detector/cxx_header/CxxVs10To14HeaderPathDetector.h
		path_detector/cxx_header/CxxVs15HeaderPathDetector.cpp
		path_detector/cxx_header/CxxVs15HeaderPathDetector.h
		path_detector/cxx_header/utilityCxxHeaderDetection.cpp
		path_detector/cxx_header/utilityCxxHeaderDetection.h

		path_detector/CombinedPathDetector.cpp
		path_detector/CombinedPathDetector.h
		path_detector/PathDetector.cpp
		path_detector/PathDetector.h

		paths/AppPath.cpp
		paths/AppPath.h
		paths/ResourcePaths.cpp
		paths/ResourcePaths.h
		paths/UserPaths.cpp
		paths/UserPaths.h

		project/Project.cpp
		project/Project.h
		project/RefreshInfo.h
		project/RefreshInfoGenerator.h
		project/RefreshInfoGenerator.cpp
		project/SourceGroup.cpp
		project/SourceGroup.h
		project/SourceGroupCustomCommand.cpp
		project/SourceGroupCustomCommand.h
		project/SourceGroupFactory.cpp
		project/SourceGroupFactory.h
		project/SourceGroupFactoryModule.cpp
		project/SourceGroupFactoryModule.h
		project/SourceGroupFactoryModuleCustom.cpp
		project/SourceGroupFactoryModuleCustom.h
		project/SourceGroupCxxCdb.cpp
		project/SourceGroupCxxCdb.h
		project/SourceGroupCxxCodeblocks.cpp
		project/SourceGroupCxxCodeblocks.h
		project/SourceGroupCxxEmpty.cpp
		project/SourceGroupCxxEmpty.h
		project/SourceGroupFactoryModuleCxx.cpp
		project/SourceGroupFactoryModuleCxx.h
		project/utilitySourceGroupCxx.cpp
		project/utilitySourceGroupCxx.h

		qt/element/bookmark/QtBookmark.cpp
		qt/element/bookmark/QtBookmark.h
		qt/element/bookmark/QtBookmarkCategory.cpp
		qt/element/bookmark/QtBookmarkCategory.h

		qt/element/button/QtHelpButton.cpp
		qt/element/button/QtHelpButton.h
		qt/element/button/QtHoverButton.cpp
		qt/element/button/QtHoverButton.h
		qt/element/button/QtIconButton.cpp
		qt/element/button/QtIconButton.h
		qt/element/button/QtIconStateButton.cpp
		qt/element/button/QtIconStateButton.h
		qt/element/button/QtSelfRefreshIconButton.cpp
		qt/element/button/QtSelfRefreshIconButton.h

		qt/element/code/CodeFocusHandler.cpp
		qt/element/code/CodeFocusHandler.h
		qt/element/code/QtCodeArea.cpp
		qt/element/code/QtCodeArea.h
		qt/element/code/QtCodeField.cpp
		qt/element/code/QtCodeField.h
		qt/element/code/QtCodeFile.cpp
		qt/element/code/QtCodeFile.h
		qt/element/code/QtCodeFileList.cpp
		qt/element/code/QtCodeFileList.h
		qt/element/code/QtCodeFileSingle.cpp
		qt/element/code/QtCodeFileSingle.h
		qt/element/code/QtCodeFileTitleBar.cpp
		qt/element/code/QtCodeFileTitleBar.h
		qt/element/code/QtCodeFileTitleButton.cpp
		qt/element/code/QtCodeFileTitleButton.h
		qt/element/code/QtCodeNavigable.cpp
		qt/element/code/QtCodeNavigable.h
		qt/element/code/QtCodeNavigator.cpp
		qt/element/code/QtCodeNavigator.h
		qt/element/code/QtCodeSnippet.cpp
		qt/element/code/QtCodeSnippet.h

		qt/element/dialog/QtLineEdit.cpp
		qt/element/dialog/QtLineEdit.h
		qt/element/dialog/QtListBox.cpp
		qt/element/dialog/QtListBox.h
		qt/element/dialog/QtListBoxItem.cpp
		qt/element/dialog/QtListBoxItem.h
		qt/element/dialog/QtLocationPicker.cpp
		qt/element/dialog/QtLocationPicker.h
		qt/element/dialog/QtPathListBox.cpp
		qt/element/dialog/QtPathListBox.h
		qt/element/dialog/QtPathListBoxItem.cpp
		qt/element/dialog/QtPathListBoxItem.h
		qt/element/dialog/QtProgressBar.cpp
		qt/element/dialog/QtProgressBar.h
		qt/element/dialog/QtStringListBox.cpp
		qt/element/dialog/QtStringListBox.h
		qt/element/dialog/QtStringListBoxItem.cpp
		qt/element/dialog/QtStringListBoxItem.h
		qt/element/dialog/QtTextEdit.cpp
		qt/element/dialog/QtTextEdit.h

		qt/element/history/QtHistoryList.cpp
		qt/element/history/QtHistoryList.h
		qt/element/history/QtUndoRedo.cpp
		qt/element/history/QtUndoRedo.h

		qt/element/search/QtAutocompletionList.cpp
		qt/element/search/QtAutocompletionList.h
		qt/element/search/QtScreenSearchBox.cpp
		qt/element/search/QtScreenSearchBox.h
		qt/element/search/QtSearchBar.cpp
		qt/element/search/QtSearchBar.h
		qt/element/search/QtSearchBarButton.cpp
		qt/element/search/QtSearchBarButton.h
		qt/element/search/QtSmartSearchBox.cpp
		qt/element/search/QtSmartSearchBox.h

		qt/element/QtTooltip.cpp
		qt/element/QtTooltip.h
		qt/element/QtStatusBar.cpp
		qt/element/QtStatusBar.h
		qt/element/QtTabBar.cpp
		qt/element/QtTabBar.h
		qt/element/QtTable.cpp
		qt/element/QtTable.h

		qt/graphics/base/QtCountCircleItem.cpp
		qt/graphics/base/QtCountCircleItem.h
		qt/graphics/base/QtLineItemAngled.cpp
		qt/graphics/base/QtLineItemAngled.h
		qt/graphics/base/QtLineItemBase.cpp
		qt/graphics/base/QtLineItemBase.h
		qt/graphics/base/QtLineItemBezier.cpp
		qt/graphics/base/QtLineItemBezier.h
		qt/graphics/base/QtLineItemStraight.cpp
		qt/graphics/base/QtLineItemStraight.h
		qt/graphics/base/QtRoundedRectItem.cpp
		qt/graphics/base/QtRoundedRectItem.h

		qt/graphics/component/QtGraphNodeComponent.cpp
		qt/graphics/component/QtGraphNodeComponent.h
		qt/graphics/component/QtGraphNodeComponentClickable.cpp
		qt/graphics/component/QtGraphNodeComponentClickable.h
		qt/graphics/component/QtGraphNodeComponentMoveable.cpp
		qt/graphics/component/QtGraphNodeComponentMoveable.h

		qt/graphics/graph/QtGraphEdge.cpp
		qt/graphics/graph/QtGraphEdge.h
		qt/graphics/graph/QtGraphNode.cpp
		qt/graphics/graph/QtGraphNode.h
		qt/graphics/graph/QtGraphNodeAccess.cpp
		qt/graphics/graph/QtGraphNodeAccess.h
		qt/graphics/graph/QtGraphNodeBundle.cpp
		qt/graphics/graph/QtGraphNodeBundle.h
		qt/graphics/graph/QtGraphNodeData.cpp
		qt/graphics/graph/QtGraphNodeData.h
		qt/graphics/graph/QtGraphNodeExpandToggle.cpp
		qt/graphics/graph/QtGraphNodeExpandToggle.h
		qt/graphics/graph/QtGraphNodeGroup.cpp
		qt/graphics/graph/QtGraphNodeGroup.h
		qt/graphics/graph/QtGraphNodeQualifier.cpp
		qt/graphics/graph/QtGraphNodeQualifier.h
		qt/graphics/graph/QtGraphNodeText.cpp
		qt/graphics/graph/QtGraphNodeText.h

		qt/graphics/GraphFocusHandler.cpp
		qt/graphics/GraphFocusHandler.h
		qt/graphics/QtGraphicsView.cpp
		qt/graphics/QtGraphicsView.h

		qt/network/QtIDECommunicationController.cpp
		qt/network/QtIDECommunicationController.h
		qt/network/QtNetworkFactory.cpp
		qt/network/QtNetworkFactory.h
		qt/network/QtRequest.cpp
		qt/network/QtRequest.h
		qt/network/QtTcpWrapper.cpp
		qt/network/QtTcpWrapper.h

		qt/project_wizard/content/path/QtProjectWizardContentPath.cpp
		qt/project_wizard/content/path/QtProjectWizardContentPath.h
		qt/project_wizard/content/path/QtProjectWizardContentPathCDB.cpp
		qt/project_wizard/content/path/QtProjectWizardContentPathCDB.h
		qt/project_wizard/content/path/QtProjectWizardContentPathCodeblocksProject.cpp
		qt/project_wizard/content/path/QtProjectWizardContentPathCodeblocksProject.h
		qt/project_wizard/content/path/QtProjectWizardContentPathCxxPch.cpp
		qt/project_wizard/content/path/QtProjectWizardContentPathCxxPch.h

		qt/project_wizard/content/paths/QtProjectWizardContentPaths.cpp
		qt/project_wizard/content/paths/QtProjectWizardContentPaths.h
		qt/project_wizard/content/paths/QtProjectWizardContentPathsExclude.cpp
		qt/project_wizard/content/paths/QtProjectWizardContentPathsExclude.h
		qt/project_wizard/content/paths/QtProjectWizardContentPathsSource.cpp
		qt/project_wizard/content/paths/QtProjectWizardContentPathsSource.h
		qt/project_wizard/content/paths/QtProjectWizardContentPathsFrameworkSearch.cpp
		qt/project_wizard/content/paths/QtProjectWizardContentPathsFrameworkSearch.h
		qt/project_wizard/content/paths/QtProjectWizardContentPathsFrameworkSearchGlobal.cpp
		qt/project_wizard/content/paths/QtProjectWizardContentPathsFrameworkSearchGlobal.h
		qt/project_wizard/content/paths/QtProjectWizardContentPathsHeaderSearch.cpp
		qt/project_wizard/content/paths/QtProjectWizardContentPathsHeaderSearch.h
		qt/project_wizard/content/paths/QtProjectWizardContentPathsHeaderSearchGlobal.cpp
		qt/project_wizard/content/paths/QtProjectWizardContentPathsHeaderSearchGlobal.h
		qt/project_wizard/content/paths/QtProjectWizardContentPathsIndexedHeaders.cpp
		qt/project_wizard/content/paths/QtProjectWizardContentPathsIndexedHeaders.h

		qt/project_wizard/content/QtProjectWizardContent.cpp
		qt/project_wizard/content/QtProjectWizardContent.h
		qt/project_wizard/content/QtProjectWizardContentCustomCommand.cpp
		qt/project_wizard/content/QtProjectWizardContentCustomCommand.h
		qt/project_wizard/content/QtProjectWizardContentExtensions.cpp
		qt/project_wizard/content/QtProjectWizardContentExtensions.h
		qt/project_wizard/content/QtProjectWizardContentGroup.cpp
		qt/project_wizard/content/QtProjectWizardContentGroup.h
		qt/project_wizard/content/QtProjectWizardContentPreferences.cpp
		qt/project_wizard/content/QtProjectWizardContentPreferences.h
		qt/project_wizard/content/QtProjectWizardContentProjectData.cpp
		qt/project_wizard/content/QtProjectWizardContentProjectData.h
		qt/project_wizard/content/QtProjectWizardContentRequiredLabel.h
		qt/project_wizard/content/QtProjectWizardContentSelect.cpp
		qt/project_wizard/content/QtProjectWizardContentSelect.h
		qt/project_wizard/content/QtProjectWizardContentSourceGroupData.cpp
		qt/project_wizard/content/QtProjectWizardContentSourceGroupData.h
		qt/project_wizard/content/QtProjectWizardContentSourceGroupInfoText.cpp
		qt/project_wizard/content/QtProjectWizardContentSourceGroupInfoText.h
		qt/project_wizard/content/QtProjectWizardContentUnloadable.cpp
		qt/project_wizard/content/QtProjectWizardContentUnloadable.h
		qt/project_wizard/content/QtProjectWizardContentCppStandard.cpp
		qt/project_wizard/content/QtProjectWizardContentCppStandard.h
		qt/project_wizard/content/QtProjectWizardContentCrossCompilationOptions.cpp
		qt/project_wizard/content/QtProjectWizardContentCrossCompilationOptions.h
		qt/project_wizard/content/QtProjectWizardContentCStandard.cpp
		qt/project_wizard/content/QtProjectWizardContentCStandard.h
		qt/project_wizard/content/QtProjectWizardContentCxxPchFlags.cpp
		qt/project_wizard/content/QtProjectWizardContentCxxPchFlags.h
		qt/project_wizard/content/QtProjectWizardContentFlags.cpp
		qt/project_wizard/content/QtProjectWizardContentFlags.h
		qt/project_wizard/content/QtProjectWizardContentVS.cpp
		qt/project_wizard/content/QtProjectWizardContentVS.h

		qt/project_wizard/QtProjectWizard.cpp
		qt/project_wizard/QtProjectWizard.h
		qt/project_wizard/QtProjectWizardWindow.cpp
		qt/project_wizard/QtProjectWizardWindow.h

		qt/utility/compatibilityQt.cpp
		qt/utility/compatibilityQt.h
		qt/utility/QtContextMenu.cpp
		qt/utility/QtContextMenu.h
		qt/utility/QtDeviceScaledPixmap.cpp
		qt/utility/QtDeviceScaledPixmap.h
		qt/utility/QtFileDialog.cpp
		qt/utility/QtFileDialog.h
		qt/utility/QtFilesAndDirectoriesDialog.cpp
		qt/utility/QtFilesAndDirectoriesDialog.h
		qt/utility/QtFlowLayout.cpp
		qt/utility/QtFlowLayout.h
		qt/utility/QtHelpButtonInfo.cpp
		qt/utility/QtHelpButtonInfo.h
		qt/utility/QtHighlighter.cpp
		qt/utility/QtHighlighter.h
		qt/utility/QtScrollSpeedChangeListener.cpp
		qt/utility/QtScrollSpeedChangeListener.h
		qt/utility/QtThreadedFunctor.h
		qt/utility/QtWindowsTaskbarButton.cpp
		qt/utility/QtWindowsTaskbarButton.h
		qt/utility/utilityQt.cpp
		qt/utility/utilityQt.h

		qt/view/QtBookmarkButtonsView.cpp
		qt/view/QtBookmarkButtonsView.h
		qt/view/QtBookmarkView.cpp
		qt/view/QtBookmarkView.h
		qt/view/QtCodeView.cpp
		qt/view/QtCodeView.h
		qt/view/QtCompositeView.cpp
		qt/view/QtCompositeView.h
		qt/view/QtCustomTrailView.cpp
		qt/view/QtCustomTrailView.h
		qt/view/QtDialogView.cpp
		qt/view/QtDialogView.h
		qt/view/QtErrorView.cpp
		qt/view/QtErrorView.h
		qt/view/QtGraphView.cpp
		qt/view/QtGraphView.h
		qt/view/QtGraphViewStyleImpl.cpp
		qt/view/QtGraphViewStyleImpl.h
		qt/view/QtMainView.cpp
		qt/view/QtMainView.h
		qt/view/QtRefreshView.cpp
		qt/view/QtRefreshView.h
		qt/view/QtScreenSearchView.cpp
		qt/view/QtScreenSearchView.h
		qt/view/QtSearchView.cpp
		qt/view/QtSearchView.h
		qt/view/QtStatusBarView.cpp
		qt/view/QtStatusBarView.h
		qt/view/QtStatusView.cpp
		qt/view/QtStatusView.h
		qt/view/QtTabbedView.cpp
		qt/view/QtTabbedView.h
		qt/view/QtTooltipView.cpp
		qt/view/QtTooltipView.h
		qt/view/QtTabsView.cpp
		qt/view/QtTabsView.h
		qt/view/QtUndoRedoView.cpp
		qt/view/QtUndoRedoView.h
		qt/view/QtViewFactory.cpp
		qt/view/QtViewFactory.h
		qt/view/QtViewWidgetWrapper.cpp
		qt/view/QtViewWidgetWrapper.h

		qt/window/QtAbout.cpp
		qt/window/QtAbout.h
		qt/window/QtBookmarkBrowser.cpp
		qt/window/QtBookmarkBrowser.h
		qt/window/QtBookmarkCreator.cpp
		qt/window/QtBookmarkCreator.h
		qt/window/QtIndexingDialog.cpp
		qt/window/QtIndexingDialog.h
		qt/window/QtIndexingProgressDialog.cpp
		qt/window/QtIndexingProgressDialog.h
		qt/window/QtIndexingReportDialog.cpp
		qt/window/QtIndexingReportDialog.h
		qt/window/QtIndexingStartDialog.cpp
		qt/window/QtIndexingStartDialog.h
		qt/window/QtKeyboardShortcuts.cpp
		qt/window/QtKeyboardShortcuts.h
		qt/window/QtKnownProgressDialog.cpp
		qt/window/QtKnownProgressDialog.h
		qt/window/QtLicenseWindow.cpp
		qt/window/QtLicenseWindow.h
		qt/window/QtMainWindow.cpp
		qt/window/QtMainWindow.h
		qt/window/QtPathListDialog.cpp
		qt/window/QtPathListDialog.h
		qt/window/QtPreferencesWindow.cpp
		qt/window/QtPreferencesWindow.h
		qt/window/QtProgressBarDialog.cpp
		qt/window/QtProgressBarDialog.h
		qt/window/QtSelectPathsDialog.cpp
		qt/window/QtSelectPathsDialog.h
		qt/window/QtStartScreen.cpp
		qt/window/QtStartScreen.h
		qt/window/QtTextEditDialog.cpp
		qt/window/QtTextEditDialog.h
		qt/window/QtUnknownProgressDialog.cpp
		qt/window/QtUnknownProgressDialog.h
		qt/window/QtWindow.cpp
		qt/window/QtWindow.h
		qt/window/QtWindowBase.cpp
		qt/window/QtWindowBase.h
		qt/window/QtWindowStack.cpp
		qt/window/QtWindowStack.h

		qt/QtApplication.cpp
		qt/QtApplication.h
		qt/QtCoreApplication.cpp
		qt/QtCoreApplication.h

		scheduling/Blackboard.cpp
		scheduling/Blackboard.h
		scheduling/Task.cpp
		scheduling/Task.h
		scheduling/TaskDecorator.cpp
		scheduling/TaskDecorator.h
		scheduling/TaskDecoratorRepeat.cpp
		scheduling/TaskDecoratorRepeat.h
		scheduling/TaskDecoratorDelay.cpp
		scheduling/TaskDecoratorDelay.h
		scheduling/TaskFindKeyOnBlackboard.cpp
		scheduling/TaskFindKeyOnBlackboard.h
		scheduling/TaskGroup.cpp
		scheduling/TaskGroup.h
		scheduling/TaskGroupParallel.cpp
		scheduling/TaskGroupParallel.h
		scheduling/TaskGroupSelector.cpp
		scheduling/TaskGroupSelector.h
		scheduling/TaskGroupSequence.cpp
		scheduling/TaskGroupSequence.h
		scheduling/TaskLambda.cpp
		scheduling/TaskLambda.h
		scheduling/TaskManager.cpp
		scheduling/TaskManager.h
		scheduling/TaskReturnSuccessIf.h
		scheduling/TaskRunner.cpp
		scheduling/TaskRunner.h
		scheduling/TaskScheduler.cpp
		scheduling/TaskScheduler.h
		scheduling/TaskSetValue.h

		settings/migration/SettingsMigration.cpp
		settings/migration/SettingsMigration.h
		settings/migration/SettingsMigrationDeleteKey.cpp
		settings/migration/SettingsMigrationDeleteKey.h
		settings/migration/SettingsMigrationLambda.cpp
		settings/migration/SettingsMigrationLambda.h
		settings/migration/SettingsMigrationMoveKey.cpp
		settings/migration/SettingsMigrationMoveKey.h
		settings/migration/SettingsMigrator.h

		settings/source_group/component/SourceGroupSettingsWithCustomCommand.cpp
		settings/source_group/component/SourceGroupSettingsWithCustomCommand.h
		settings/source_group/component/SourceGroupSettingsWithExcludeFilters.cpp
		settings/source_group/component/SourceGroupSettingsWithExcludeFilters.h
		settings/source_group/component/SourceGroupSettingsWithSourceExtensions.cpp
		settings/source_group/component/SourceGroupSettingsWithSourceExtensions.h
		settings/source_group/component/SourceGroupSettingsWithSourceExtensionsEmpty.h
		settings/source_group/component/SourceGroupSettingsWithSourcePaths.cpp
		settings/source_group/component/SourceGroupSettingsWithSourcePaths.h

		settings/source_group/component/cxx/SourceGroupSettingsWithCppStandard.cpp
		settings/source_group/component/cxx/SourceGroupSettingsWithCppStandard.h
		settings/source_group/component/cxx/SourceGroupSettingsWithCStandard.cpp
		settings/source_group/component/cxx/SourceGroupSettingsWithCStandard.h
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxCdbPath.cpp
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxCdbPath.h
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxCodeblocksPath.cpp
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxCodeblocksPath.h
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxCrossCompilationOptions.cpp
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxCrossCompilationOptions.h
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxPathsAndFlags.cpp
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxPathsAndFlags.h
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxPchOptions.cpp
		settings/source_group/component/cxx/SourceGroupSettingsWithCxxPchOptions.h
		settings/source_group/component/cxx/SourceGroupSettingsWithIndexedHeaderPaths.cpp
		settings/source_group/component/cxx/SourceGroupSettingsWithIndexedHeaderPaths.h
		settings/source_group/component/cxx/SourceGroupSettingsWithSourceExtensionsC.h
		settings/source_group/component/cxx/SourceGroupSettingsWithSourceExtensionsCpp.h

		settings/source_group/type/SourceGroupSettingsCEmpty.h
		settings/source_group/type/SourceGroupSettingsCppEmpty.h
		settings/source_group/type/SourceGroupSettingsCustomCommand.h
		settings/source_group/type/SourceGroupSettingsCxxCdb.h
		settings/source_group/type/SourceGroupSettingsCxxCodeblocks.h
		settings/source_group/type/SourceGroupSettingsUnloadable.cpp
		settings/source_group/type/SourceGroupSettingsUnloadable.h

		settings/source_group/SourceGroupSettings.cpp
		settings/source_group/SourceGroupSettings.h
		settings/source_group/SourceGroupSettingsBase.h
		settings/source_group/SourceGroupSettingsWithComponents.h
		settings/source_group/SourceGroupStatusType.cpp
		settings/source_group/SourceGroupStatusType.h
		settings/source_group/SourceGroupType.cpp
		settings/source_group/SourceGroupType.h

		settings/ApplicationSettings.cpp
		settings/ApplicationSettings.h
		settings/ApplicationSettingsPrefiller.cpp
		settings/ApplicationSettingsPrefiller.h
		settings/ColorScheme.cpp
		settings/ColorScheme.h
		settings/LanguageType.cpp
		settings/LanguageType.h
		settings/ProjectSettings.cpp
		settings/ProjectSettings.h
		settings/Settings.cpp
		settings/Settings.h

		text/TextAccess.cpp
		text/TextAccess.h

		utility/TextCodec.cpp
		utility/TextCodec.h
		utility/utilityString.cpp
		utility/utilityString.h

		# TODO: hardcoded file: use ExternalProject or CPM
		${CMAKE_SOURCE_DIR}/src/external/sqlite/CppSQLite3.cpp
)

## TODO: verify
if (WIN32)
	# TODO: use qt-resource
	#	file(WRITE ${CMAKE_BINARY_DIR}/Sourcetrail.rc
	#		"// Icon with lowest ID value placed first to ensure application icon\n"
	#		"// remains consistent on all systems.\n"
	#		"IDI_ICON1               ICON                    \"${CMAKE_BINARY_DIR}/Sourcetrail.ico\"\n"
	#	)
	#	add_executable(sourcetrail ${APP_FILES} ${CMAKE_BINARY_DIR}/Sourcetrail.rc)

	# also show the console when running a release build.
	set_target_properties(source-inspector PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE /DEBUG:FASTLINK")
	set_target_properties(source-inspector PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
	set_target_properties(source-inspector PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
	set_target_properties(source-inspector PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
	set_target_properties(source-inspector PROPERTIES LINK_FLAGS_RELEASE "/ENTRY:\"mainCRTStartup\" /SUBSYSTEM:CONSOLE /DEBUG")
	set_target_properties(source-inspector PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:CONSOLE")

	# generate pdb for release build
	# set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")

	# set_property(TARGET ${APP_PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/app")

	#string(REGEX REPLACE "/" "\\\\" BACKSLASHED_CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR})
	#string(REGEX REPLACE "/" "\\\\" BACKSLASHED_CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR})
endif ()

## Dependencies
##
set(Boost_USE_MULTITHREAD ON)
set(Boost_USE_STATIC_LIBS ON CACHE BOOL "Set to ON to force the use of the static libraries.")
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.67 COMPONENTS system program_options filesystem date_time REQUIRED)

set(QT_MIN_VERSION "5.12.0")
find_package(Qt5 ${QT_MIN_VERSION} COMPONENTS Widgets Network REQUIRED) # PrintSupport Svg
if (WIN32)
	find_package(Qt5 ${QT_MIN_VERSION} COMPONENTS WinExtras REQUIRED)
endif ()

find_package(unofficial-sqlite3 CONFIG REQUIRED)
find_package(tinyxml CONFIG REQUIRED)

find_package(Clang REQUIRED)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)

llvm_map_components_to_libnames(llvm_libs
		Analysis
		Core
		ExecutionEngine
		LibDriver
		Passes
		Option
		Support)

foreach (LLVM_TARGET ${LLVM_TARGETS_TO_BUILD})
	list(APPEND llvm_libs "LLVM${LLVM_TARGET}CodeGen")
	list(APPEND llvm_libs "LLVM${LLVM_TARGET}AsmParser")
endforeach ()

target_compile_definitions(source-inspector PRIVATE ${LLVM_DEFINITIONS})

target_link_libraries(source-inspector PRIVATE enable_compiler_warnings)
target_link_libraries(source-inspector PRIVATE clangASTMatchers)
target_link_libraries(source-inspector PRIVATE clangFrontend)
target_link_libraries(source-inspector PRIVATE clangSerialization)
target_link_libraries(source-inspector PRIVATE clangDriver)
target_link_libraries(source-inspector PRIVATE clangTooling)
target_link_libraries(source-inspector PRIVATE clangParse)
target_link_libraries(source-inspector PRIVATE clangSema)
target_link_libraries(source-inspector PRIVATE clangStaticAnalyzerFrontend)
target_link_libraries(source-inspector PRIVATE clangStaticAnalyzerCheckers)
target_link_libraries(source-inspector PRIVATE clangStaticAnalyzerCore)
target_link_libraries(source-inspector PRIVATE clangAnalysis)
target_link_libraries(source-inspector PRIVATE clangRewriteFrontend)
target_link_libraries(source-inspector PRIVATE clangEdit)
target_link_libraries(source-inspector PRIVATE clangAST)
target_link_libraries(source-inspector PRIVATE clangLex)
target_link_libraries(source-inspector PRIVATE clangBasic)
target_link_libraries(source-inspector PRIVATE ${llvm_libs})
target_link_libraries(source-inspector PRIVATE Boost::boost)
target_link_libraries(source-inspector PRIVATE Boost::filesystem)
target_link_libraries(source-inspector PRIVATE Boost::program_options)
target_link_libraries(source-inspector PRIVATE Qt5::Widgets)
target_link_libraries(source-inspector PRIVATE Qt5::Network)
target_link_libraries(source-inspector PRIVATE unofficial::sqlite3::sqlite3)
target_link_libraries(source-inspector PRIVATE unofficial-tinyxml::unofficial-tinyxml)


## TODO: verify
# add platform specific libraries
if (APPLE)
	find_library(CORE_FOUNDATION CoreFoundation)
	target_link_libraries(source-inspector PRIVATE ${CORE_FOUNDATION})
endif ()

## TODO: verify
message(STATUS "create symlink: ${CMAKE_SOURCE_DIR}/bin/app/data -> ${CMAKE_CURRENT_BINARY_DIR}/app/data")
execute_process(
		COMMAND "${CMAKE_COMMAND}" "-E" "create_symlink" "${CMAKE_SOURCE_DIR}/bin/app/data" "${CMAKE_CURRENT_BINARY_DIR}/data"
		COMMAND "${CMAKE_COMMAND}" "-E" "create_symlink" "${CMAKE_SOURCE_DIR}/bin/app/user" "${CMAKE_CURRENT_BINARY_DIR}/user"
)


## TODO: verify
if (APPLE)
	set(MACOS_BUNDLE_NAME ${PROJECT_NAME})
	set(MACOS_BUNDLE_VERSION ${VERSION_STRING})
	set(MACOS_BINARY_NAME ${APP_PROJECT_NAME})
	set(MACOS_INDEXER_BINARY_NAME ${APP_INDEXER_NAME})

	get_property(QT_CORE_PATH TARGET ${Qt5Core_LIBRARIES} PROPERTY LOCATION)
	get_filename_component(QT_CORE_PATH ${QT_CORE_PATH} REALPATH)

	get_property(QT_GUI_PATH TARGET ${Qt5Gui_LIBRARIES} PROPERTY LOCATION)
	get_filename_component(QT_GUI_PATH ${QT_GUI_PATH} REALPATH)

	get_property(QT_WIDGETS_PATH TARGET ${Qt5Widgets_LIBRARIES} PROPERTY LOCATION)
	get_filename_component(QT_WIDGETS_PATH ${QT_WIDGETS_PATH} REALPATH)

	get_property(QT_PRINT_PATH TARGET ${Qt5PrintSupport_LIBRARIES} PROPERTY LOCATION)
	get_filename_component(QT_PRINT_PATH ${QT_PRINT_PATH} REALPATH)

	get_property(QT_NETWORK_PATH TARGET ${Qt5Network_LIBRARIES} PROPERTY LOCATION)
	get_filename_component(QT_NETWORK_PATH ${QT_NETWORK_PATH} REALPATH)

	get_property(QT_SVG_PATH TARGET ${Qt5Svg_LIBRARIES} PROPERTY LOCATION)
	get_filename_component(QT_SVG_PATH ${QT_SVG_PATH} REALPATH)

	list(APPEND MACOS_QT_FRAMEWORKS ${QT_CORE_PATH} ${QT_GUI_PATH} ${QT_WIDGETS_PATH} ${QT_PRINT_PATH} ${QT_NETWORK_PATH} ${QT_SVG_PATH})
	string(REPLACE ";" " " MACOS_QT_FRAMEWORKS "${MACOS_QT_FRAMEWORKS}")

	set(MACOS_BOOST_DIR "${Boost_INCLUDE_DIR}")
	STRING(REGEX REPLACE "/lib/cmake/clang" "" MACOS_CLANG_DIR "${Clang_DIR}")
	STRING(REGEX REPLACE "/lib/cmake/Qt5" "" MACOS_QT_DIR "${Qt5_DIR}")

	configure_file(
			${PROJECT_SOURCE_DIR}/setup/macOS/bundle_install.sh.in
			${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bundle_install.sh
			@ONLY
	)
	configure_file(
			${PROJECT_SOURCE_DIR}/setup/macOS/bundle_info.plist.in
			${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bundle_info.plist
			@ONLY
	)
endif ()
